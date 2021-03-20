/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio_wrapper
    DESCRIPTION:    An ASIO wrapper
    VERSION:        1.0.0

    FILE:           example/server.cpp
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include <atomic>
#include <iostream>

#include "asio_wrapper/asio_wrapper.hpp"

// Some boiler plate signal handling code
std::atomic<bool> stop_flag;
void signalHandler(int signum) {
  stop_flag = true;
}

// Create a callback handler class
class WritableHandlerImplServer : public cppeng::tcp::WritableHandler {
 public:
  void HandleCallback(std::vector<uint8_t> data,
                      std::shared_ptr<cppeng::tcp::Writable> writable) override {
    std::string received(data.begin(), data.end());
    std::cout << "Server Rx: " << received << std::endl;
    const std::string default_reply = "HTTP/1.1 200 OK\r\n"
                                      "Content-Type: text/html\r\n"
                                      "Connection: close\r\n"
                                      "Content-Length: 24\r\n"
                                      "\r\n"
                                      "<h1>C++ is Awesome!</h1>";
    writable->Write(default_reply);
  }
  void NotifyClosed(std::shared_ptr<cppeng::tcp::Writable> ptr) override {
    std::cout << "Server: A connection was closed!" << std::endl;
  }
};

int main(int argc, char **argv) {
  // Register signal
  signal(SIGINT, signalHandler);
  stop_flag = false;

  // Create callback handler
  WritableHandlerImplServer writable_handler_server;

  // Create and start the server at port 3000
  cppeng::tcp::Server server(3000, writable_handler_server);
  server.Start();

  // Wait until program is terminated
  while (!stop_flag) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  // Stop the server
  server.Stop();

  // Exit
  return EXIT_SUCCESS;
}