/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/connector.h
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#ifndef ASIO_WRAPPER_TCP_CONNECTOR_H_
#define ASIO_WRAPPER_TCP_CONNECTOR_H_

#include <string>

#include "asio.hpp"
#include "interfaces/writable.h"
#include "interfaces/writable_handler.h"
#include "tcp/connection_manager.h"

namespace cppeng {
namespace tcp {

class Connector: public interfaces::Writable {
public:
	Connector(asio::io_context& io_context,
		std::string address,
		int port,
		interfaces::WritableHandler& writable_handler);
	void Write(void* data, int len) override;
	bool IsConnected() const;
private:
	const std::string address_;
	const int port_;
	ConnectionManager connection_manager_;
	asio::ip::tcp::socket socket_;
	asio::io_context &io_context_;
	interfaces::WritableHandler& writable_handler_;
	bool connected_;
	void DoConnect(const asio::ip::tcp::resolver::results_type& endpoints);
};

} // namespace tcp
} // namespace cppeng

#endif // ASIO_WRAPPER_TCP_CONNECTOR_H_
