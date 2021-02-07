/*******************************************************************************
																			  
    COPYRIGHT:      Cpp::Engineer 2021										  

    LICENCE:        MIT                                                       
    PROJECT:        asio-wrapper									              
    DESCRIPTION:    An ASIO wrapper									      

    FILE:           tcp/server.h                							      
    URL: 	        https://github.com/cppengineer/asio-wrapper		          
															                  
*******************************************************************************/

#ifndef ASIO_WRAPPER_TCP_SERVER_H_
#define ASIO_WRAPPER_TCP_SERVER_H_

#include <thread>

#include "asio.hpp"
#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"
#include "tcp/acceptor.h"

namespace cppeng {
namespace tcp {

class Server: public interfaces::Writable {
 public:
  Server(int port, interfaces::WritableHandler &writable_handler);
  bool Start();
  bool Stop();
  void Write(void* data, int len) override;
private:
    asio::io_context io_context_;
    std::unique_ptr<Acceptor> acceptor_;
    interfaces::WritableHandler& writable_handler_;
    std::thread worker_;
};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_SERVER_H_
