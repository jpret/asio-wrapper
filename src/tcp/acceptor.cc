/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/acceptor.cc
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include "tcp/acceptor.h"

#include "tcp/connection.h"

namespace cppeng {
namespace tcp {

Acceptor::Acceptor(asio::io_context& io_context,
                    const asio::ip::tcp::endpoint& endpoint,
                    interfaces::WritableHandler& writable_handler)
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

} // namespace tcp
} // namespace cppeng