/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/connection.cc
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include "tcp/connection.h"

namespace cppeng {
namespace tcp {

Connection::Connection(asio::io_context& io_context,
                       asio::ip::tcp::socket socket,
                       tcp::IConnectionManager& connection_manager,
                       interfaces::WritableHandler& writable_handler)
    : io_context_(io_context),
      socket_(std::move(socket)),
      connection_manager_(connection_manager),
      writable_handler_(writable_handler),
      write_queue_{},
      read_buffer_{},
      write_busy_{}  {}
        
bool Connection::Start() {
    // Connect ourselves to the connection manager
    connection_manager_.Connect(shared_from_this());
    // Start the read_process
    DoRead();
    // Return the result
    return true;
}

void Connection::Close() {
    // Disconnect ourselves from the connection manager
    connection_manager_.Disconnect(shared_from_this());

    // Stop the socket in the io_context thread as well
    // Todo: Fix this
       // asio::post(io_context_, [this]() { socket_.close(); });
}

void Connection::Write(void* data, int len) {
    // Allocate memory for the buffer
    uint8_t* buffer = new uint8_t[len];
    memcpy(buffer, (uint8_t*)data, len);
    auto pair = std::pair<int, uint8_t*>(len, buffer);
    // Add the buffer t the queue
    write_queue_.push(pair);
    // Start the write process only if we are not already busy writing
    if (!write_busy_) {
        write_busy_ = true;
        DoWrite();
    }
}

void Connection::DoRead() {
    auto self(shared_from_this());
    asio::async_read(socket_,
        asio::buffer(read_buffer_.data(), read_buffer_.size()),
        asio::transfer_at_least(1),
        [this, self](std::error_code ec, std::size_t length) {
        if (!ec) {
            writable_handler_.HandleCallback(read_buffer_.data(), length, 
                                             shared_from_this());
            DoRead();
        } else {
            Close();
        }
    });
}

void Connection::DoWrite() {
    auto self(shared_from_this());
    asio::async_write(socket_,
        asio::buffer(write_queue_.front().second,
            write_queue_.front().first),
        [this, self](std::error_code ec, std::size_t /*length*/) {
        if (!ec) {
            // Delete the write queue's memory allocated for write
            delete [] write_queue_.front().second;
            write_queue_.front().second = nullptr;
            write_queue_.pop();
            if (!write_queue_.empty()) {
                DoWrite();
            } else {
                write_busy_ = false;
            }
        }
        else {
            Close();
        }
    });
}

} // namespace tcp
} // namespace cppeng