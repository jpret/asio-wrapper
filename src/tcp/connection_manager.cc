/*******************************************************************************

	COPYRIGHT:      Cpp::Engineer 2021

	LICENCE:        MIT
	PROJECT:        asio-wrapper
	DESCRIPTION:    An ASIO wrapper

	FILE:           tcp/connection_manager.cc
	URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include "tcp/connection_manager.h"

namespace cppeng {
namespace tcp {

void ConnectionManager::Connect(std::shared_ptr<interfaces::Writable> writable) {
	// Insert the writable into the list
	writables_.insert(writable);
}

void ConnectionManager::Disconnect(std::shared_ptr<interfaces::Writable> writable) {
	// Remove the writable from the list
	writables_.erase(writable);
}

void ConnectionManager::Write(void* data, int len) {
	for (auto& writable : writables_) {
		writable->Write(data, len);
	}
}

} // namespace tcp
} // namespace cppeng