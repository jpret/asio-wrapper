/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper
    VERSION:        1.0.0

    FILE:           asio-wrapper.cpp
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include "asio-wrapper.hpp"

#include <chrono>

namespace cppeng {
namespace tcp {

Connection::Connection(asio::io_context& io_context,
    asio::ip::tcp::socket socket,
    tcp::IConnectionManager& connection_manager,
    WritableHandler& writable_handler)
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
        }
        else {
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
            delete[] write_queue_.front().second;
            write_queue_.front().second = nullptr;
            write_queue_.pop();
            if (!write_queue_.empty()) {
                DoWrite();
            }
            else {
                write_busy_ = false;
            }
        }
        else {
            Close();
        }
    });
}

void ConnectionManager::Connect(std::shared_ptr<Writable> writable) {
    // Insert the writable into the list
    writables_.insert(writable);
}

void ConnectionManager::Disconnect(std::shared_ptr<Writable> writable) {
    // Remove the writable from the list
    writables_.erase(writable);
}

void ConnectionManager::Write(void* data, int len) {
    for (auto& writable : writables_) {
        writable->Write(data, len);
    }
}

Connector::Connector(asio::io_context& io_context,
    std::string address,
    int port,
    WritableHandler& writable_handler)
    : io_context_(io_context),
    socket_(io_context),
    address_(std::move(address)),
    port_(port),
    writable_handler_(writable_handler),
    connected_(false) {
    // Resolve the endpoint for the provided address and port
    asio::ip::tcp::resolver resolver(io_context);
    auto endpoints = resolver.resolve(address_, std::to_string(port));
    DoConnect(endpoints);
}

void Connector::DoConnect(const asio::ip::tcp::resolver::results_type& endpoints) {
    asio::async_connect(socket_, endpoints,
        [this](std::error_code ec, asio::ip::tcp::endpoint) {
        if (!ec) {
            std::make_shared<Connection>(io_context_, std::move(socket_),
                connection_manager_, writable_handler_)->Start();
            connected_ = true;
        }
    });
}

void Connector::Write(void* data, int len) {
    connection_manager_.Write(data, len);
}

bool Connector::IsConnected() const {
    return connected_;
}


Acceptor::Acceptor(asio::io_context& io_context,
    const asio::ip::tcp::endpoint& endpoint,
    WritableHandler& writable_handler)
    : io_context_(io_context),
    acceptor_(io_context, endpoint),
    writable_handler_(writable_handler) {
    DoAccept();
}

void Acceptor::DoAccept() {
    acceptor_.async_accept(
        [this](std::error_code ec, asio::ip::tcp::socket socket) {
        if (!ec) {
            std::make_shared<Connection>(io_context_, std::move(socket),
                connection_manager_, writable_handler_)->Start();
        }
        DoAccept();
    });
}

void Acceptor::Write(void* data, int len) {
    connection_manager_.Write(data, len);
}

Client::Client(std::string address, int port,
    WritableHandler& writable_handler)
    : address_(std::move(address)),
    port_(port),
    writable_handler_(writable_handler) { }

bool Client::Start(int timeout_ms) {
    bool result = false;
    // First check if the worker is already running / not
    if (!worker_.joinable()) {
        // We'll initiate the connect
        connector_ = std::unique_ptr<Connector>(new Connector(io_context_,
            address_, port_, writable_handler_));
        // Start the thread
        worker_ = std::thread([&]() {
            io_context_.run();
        });

        auto time_now = std::chrono::high_resolution_clock::now();
        auto time_goal = std::chrono::high_resolution_clock::now();
        // Wait for the timeout
        while (!connector_->IsConnected() && std::chrono::duration_cast<std::chrono::milliseconds>(
            time_goal - time_now).count() < timeout_ms) {
            // Just wait for the connection.
            time_goal = std::chrono::high_resolution_clock::now();
        }
        if (connector_->IsConnected()) {
            result = true;
        }
        else {
            Stop();
        }
    }
    return result;
}

bool Client::Stop() {
    bool result = false;
    // First check if the worker is already running / not
    if (worker_.joinable()) {
        io_context_.stop();
        worker_.join();
        // Reset our worker
        io_context_.reset();
        result = true;
    }
    return result;
}

void Client::Write(void* data, int len) {
    connector_->Write(data, len);
}


Server::Server(int port, WritableHandler& writable_handler)
    : writable_handler_(writable_handler) {
    asio::ip::tcp::endpoint endpoint(asio::ip::tcp::v4(), port);
    acceptor_ = std::unique_ptr<Acceptor>(new Acceptor(io_context_, endpoint, writable_handler_));
}

bool Server::Start() {
    bool result = false;
    // First check if the worker is already running / not
    if (!worker_.joinable()) {
        worker_ = std::thread([&]() {
            io_context_.run();
        });
        result = true;
    }
    return result;
}

bool Server::Stop() {
    bool result = false;
    // First check if the worker is already running / not
    if (worker_.joinable()) {
        io_context_.stop();
        worker_.join();
        // Reset our worker
        io_context_.reset();
        result = true;
    }
    return result;
}

void Server::Write(void* data, int len) {
    acceptor_->Write(data, len);
}


} // namespace tcp
} // namespace cppeng