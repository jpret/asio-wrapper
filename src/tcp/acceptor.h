/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/acceptor.h
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#ifndef ASIO_WRAPPER_TCP_ACCEPTOR_H_
#define ASIO_WRAPPER_TCP_ACCEPTOR_H_

#include <string>

#include "asio/asio.hpp"
#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"

namespace cppeng {
namespace tcp {

class Acceptor: public interfaces::Writable {
 public:

     // Add socket connection acceptor methods here

};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_ACCEPTOR_H_
