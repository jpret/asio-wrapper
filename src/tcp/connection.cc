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

    bool Connection::Start() {
        // Connect ourselves to the connection manager
        connection_manager_.Connect(shared_from_this());

        //TODO: Start the do read process here
        return false;
    }

    void Connection::Close() {
        // Disconnect ourselves from the connection manager
        connection_manager_.Disconnect(shared_from_this());

        //TODO: Stop the connection here

    }

    void Connection::Write(void* data, int len) {
        //TODO: Implement Asio Read some and Write some methods here
    }




} // namespace tcp
} // namespace cppeng