/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           interfaces/writable.h
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#ifndef ASIO_WRAPPER_INTERFACES_WRITABLE_H_
#define ASIO_WRAPPER_INTERFACES_WRITABLE_H_

namespace cppeng {
namespace interfaces {

class Writable {
 public:
  virtual void Write(void* data, int len) = 0;
  virtual ~Writable() = default;
};

} // namespace interfaces
} // namespace cppeng

#endif // ASIO_WRAPPER_INTERFACES_WRITABLE_H_
