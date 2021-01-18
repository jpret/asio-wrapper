/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/client.cc
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include "tcp/client.h"

namespace cppeng {
namespace tcp {

bool Client::Initialise(int port, const std::string& address,
    interfaces::WritableHandler& writable_handler) {

    //TODO: Implement

    return false;
}

bool Client::Start(int connect_timeout) {
    
    // TODO: Implement

    return false;
}

bool Client::Stop() {

    // TODO: Implement

    return false;
}

void Write(void* data, int len) {

    // TODO: Implement

}



} // namespace tcp
} // namespace cppeng