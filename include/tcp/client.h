/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/client.h
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#ifndef ASIO_WRAPPER_TCP_CLIENT_H_
#define ASIO_WRAPPER_TCP_CLIENT_H_

#include <string>

#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"

namespace cppeng {
namespace tcp {

class Client: public interfaces::Writable {
 public:
  bool Initialise(int port, const std::string& address,
                  interfaces::WritableHandler& writable_handler);
  bool Start(int connect_timeout);
  bool Stop();
  void Write(void* data, int len) override;
};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_CLIENT_H_
