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

#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"

namespace cppeng {
namespace tcp {

class Server: public interfaces::Writable {
 public:
  bool Initialise(int port, interfaces::WritableHandler &writable_handler);
  bool Start();
  bool Stop();
  void Write(void* data, int len) override;
};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_SERVER_H_
