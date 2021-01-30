/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/client.cc
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include <chrono>

#include "tcp/client.h"

namespace cppeng {
namespace tcp {

Client::Client(std::string address, int port,
    interfaces::WritableHandler& writable_handler)
  : address_(std::move(address)),
    port_(port),
    writable_handler_(writable_handler) { }

bool Client::Start(int timeout_ms) {
    bool result = false;
    // First check if the worker is already running / not
    if (!worker_.joinable()) {
        // We'll initiate the connect
        connector_ = std::unique_ptr<Connector>(new Connector(io_context_,
            address_, port_, writable_handler_));
        // Start the thread
        worker_ = std::thread([&]() {
            io_context_.run();
        });

        auto time_now = std::chrono::high_resolution_clock::now();
        auto time_goal = std::chrono::high_resolution_clock::now();
        // Wait for the timeout
        while (!connector_->IsConnected() && std::chrono::duration_cast<std::chrono::milliseconds>(
            time_goal - time_now).count() < timeout_ms) {
            // Just wait for the connection.
            time_goal = std::chrono::high_resolution_clock::now();
        }
        if (connector_->IsConnected()) {
            result = true;
        }
        else {
            Stop();
        }
    }
    return result;
}

bool Client::Stop() {
    bool result = false;
    // First check if the worker is already running / not
    if (worker_.joinable()) {
        io_context_.stop();
        worker_.join();
        // Reset our worker
        io_context_.reset();
        result = true;
    }
    return result;
}

void Client::Write(void* data, int len) {
    connector_->Write(data, len);
}

} // namespace tcp
} // namespace cppeng