/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           interfaces/connection_manager.h
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#ifndef ASIO_WRAPPER_INTERFACES_CONNECTION_MANAGER_H_
#define ASIO_WRAPPER_INTERFACES_CONNECTION_MANAGER_H_

#include "interfaces/writable.h"

namespace cppeng {
namespace tcp {

class IConnectionManager {
public:
    virtual void Connect(std::shared_ptr<interfaces::Writable> writable) = 0;
    virtual void Disconnect(std::shared_ptr<interfaces::Writable> writable) = 0;    
};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_INTERFACES_CONNECTION_MANAGER_H_
