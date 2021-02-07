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

#include <set>
#include <string>

#include "asio.hpp"
#include "interfaces/connection_manager.h"
#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"

namespace cppeng {
namespace tcp {

class ConnectionManager: public interfaces::Writable,
                         public tcp::IConnectionManager {
 public:
     void Connect(std::shared_ptr<interfaces::Writable> writable) override;

     void Disconnect(std::shared_ptr<interfaces::Writable> writable) override;

     void Write(void* data, int len) override;
private:
    std::set<std::shared_ptr<interfaces::Writable>> writables_;
};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_CONNECTION_MANAGER_H_
