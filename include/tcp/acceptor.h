/*******************************************************************************

	COPYRIGHT:      Cpp::Engineer 2021

	LICENCE:        MIT
	PROJECT:        asio-wrapper
	DESCRIPTION:    An ASIO wrapper

	FILE:           tcp/acceptor.h
	URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#ifndef ASIO_WRAPPER_TCP_ACCEPTOR_H_
#define ASIO_WRAPPER_TCP_ACCEPTOR_H_

#include <string>

#include "asio/asio.hpp"
#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"
#include "tcp/connection_manager.h"

namespace cppeng {
namespace tcp {

class Acceptor : public interfaces::Writable {
public:
	Acceptor(asio::io_context& io_context,
			 const asio::ip::tcp::endpoint& endpoint,
			 interfaces::WritableHandler& writable_handler);
	void Write(void* data, int len) override;
private:
	asio::io_context& io_context_;
	asio::ip::tcp::acceptor acceptor_;
	ConnectionManager connection_manager_;
	interfaces::WritableHandler& writable_handler_;
	void DoAccept();
};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_ACCEPTOR_H_
