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

#include <array>
#include <string>
#include <queue>

#include "asio/asio.hpp"
#include "interfaces/connection_manager.h"
#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"

namespace cppeng {
namespace tcp {

class Connection: public interfaces::Writable, 
                  public std::enable_shared_from_this<Connection> {
 public:
     Connection(asio::ip::tcp::socket socket,
                tcp::IConnectionManager& connection_manager,
                interfaces::WritableHandler& writable_handler);
     
     bool Start();

     void Close();

     void Write(void* data, int len) override;

private:

    void DoWrite();

    void DoRead();

    tcp::IConnectionManager& connection_manager_;
    interfaces::WritableHandler& writable_handler_;
    asio::ip::tcp::socket socket_;
    std::array<uint8_t, 8192> read_buffer_;
    std::queue<std::pair<int, uint8_t*>> write_queue_;
};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_ACCEPTOR_H_
