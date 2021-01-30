/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/acceptor.cc
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include "tcp/connector.h"

#include "tcp/connection.h"

namespace cppeng {
namespace tcp {

Connector::Connector(asio::io_context& io_context,
    std::string address,
    int port,
    interfaces::WritableHandler& writable_handler)
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

} // namespace tcp
} // namespace cppeng