/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio_wrapper
    DESCRIPTION:    An ASIO wrapper
    VERSION:        1.0.0

    FILE:           example/client.cpp
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
class WritableHandlerImplClient : public cppeng::tcp::WritableHandler {
 public:
  void HandleCallback(std::vector<uint8_t> data,
                      std::shared_ptr<cppeng::tcp::Writable> writable) override {
    // Convert void pointer to string
    std::string received(data.begin(), data.end());
    std::cout << "Client Rx: " << received << std::endl;
    rx_flag_ = true;
  }
  void NotifyClosed(std::shared_ptr<cppeng::tcp::Writable> ptr) override {
    std::cout << "Client: A Connection was closed!" << std::endl;
    stop_flag = true;
  }
  bool rx_flag_{false};
};

int main(int argc, char **argv) {
  // Register signal
  signal(SIGINT, signalHandler);
  stop_flag = false;

  // Create callback handler
  WritableHandlerImplClient writable_handler_client;

  // Connect to google
  cppeng::tcp::Client client("cppengineer.com",
                             80,
                             writable_handler_client);
  // Or to a local server
  //  cppeng::tcp::Client client("127.0.0.1",
  //                             3000,
  //                             writable_handler_client);

  // Connect and write some stuff to the server
  bool connected = false;
  int counter = 0;
  do {
    // Try to connect at least for 20 seconds
    connected = client.Start(1000);
    if (!connected) {
      std::cout << "Trying to connect: " << ++counter << std::endl;
    }
  } while (!connected && counter < 20);

  // If connected then write something to the server
  if (connected) {
    // Write something to the server
    std::string default_request("GET / HTTP/1.1\n\r"
                                "Host:127.0.0.1\r\n"
                                "Connection: close\n\r"
                                "\n\r");
    client.Write(default_request);
    while (!writable_handler_client.rx_flag_ && !stop_flag) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    // Stop the client and the server
    client.Stop();
  }

  // Exit
  return EXIT_SUCCESS;
}