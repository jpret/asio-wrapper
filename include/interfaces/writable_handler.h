/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           interfaces/writable_handler.h
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#ifndef ASIO_WRAPPER_INTERFACES_WRITABLE_HANDLER_H_
#define ASIO_WRAPPER_INTERFACES_WRITABLE_HANDLER_H_

#include <memory>

#include "interfaces/Writable.h"

namespace cppeng {
namespace interfaces {

class WritableHandler {
 public:
  virtual void HandleCallback(void* data, int len,
                              std::shared_ptr<Writable>) = 0;
  virtual ~WritableHandler() = default;
};

} // namespace interfaces
} // namespace cppeng

#endif // ASIO_WRAPPER_INTERFACES_WRITABLE_HANDLER_H_
