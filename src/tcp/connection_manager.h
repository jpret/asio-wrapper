/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/connection_manager.h
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#ifndef ASIO_WRAPPER_TCP_CONNECTION_MANAGER_H_
#define ASIO_WRAPPER_TCP_CONNECTION_MANAGER_H_

#include <string>

#include "asio/asio.hpp"
#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"

namespace cppeng {
namespace tcp {

class Connection: public interfaces::Writable {
 public:

     // Add socket connection manager methods here

};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_CONNECTION_MANAGER_H_
