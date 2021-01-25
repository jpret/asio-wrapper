/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/connection.h
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#ifndef ASIO_WRAPPER_TCP_CONNECTION_H_
#define ASIO_WRAPPER_TCP_CONNECTION_H_

#include <string>

#include "asio/asio.hpp"
#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"
#include "tcp/connection_manager_interface.h"

namespace cppeng {
namespace tcp {

class Connection: public interfaces::Writable, 
                  public std::enable_shared_from_this<Connection> {
 public:
     Connection(asio::ip::tcp::socket socket, 
                tcp::IConnectionManager &connection_manager,
                interfaces::WritableHandler& writable_handler)
         : socket_(std::move(socket)),
           connection_manager_(connection_manager),
           writable_handler_(writable_handler) {}
     
     bool Start();

     void Close();

     void Write(void* data, int len) override;

private:
    tcp::IConnectionManager& connection_manager_;
    interfaces::WritableHandler& writable_handler_;
    asio::ip::tcp::socket socket_;
};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_ACCEPTOR_H_
