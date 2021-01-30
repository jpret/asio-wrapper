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
#include <thread>

#include "asio/asio.hpp"
#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"
#include "tcp/connector.h"

namespace cppeng {
namespace tcp {

class Client : public interfaces::Writable {
 public:
    Client(std::string address, int port, 
           interfaces::WritableHandler& writable_handler);
    bool Start(int timeout_ms);
    bool Stop();
    void Write(void* data, int len) override;
 private:
    const std::string address_;
    int port_;
    asio::io_context io_context_;
    std::unique_ptr<Connector> connector_;
    interfaces::WritableHandler& writable_handler_;
    std::thread worker_;
};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_CLIENT_H_
