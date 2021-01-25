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
    io_context_.run();
    return true;
}

bool Server::Stop() {

    // Todo:: Implement

    return false;
}

void Server::Write(void* data, int len) {

    // Todo:: Implement

}

} // namespace tcp
} // namespace cppeng