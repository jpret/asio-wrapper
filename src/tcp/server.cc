/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/server.cc
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include "tcp/server.h"

namespace cppeng {
namespace tcp {

Server::Server(int port, interfaces::WritableHandler& writable_handler)
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