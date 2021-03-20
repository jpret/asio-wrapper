/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio_wrapper
    DESCRIPTION:    An ASIO wrapper
    VERSION:        1.0.0

    FILE:           asio_wrapper_test.cpp
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include <vector>

#include "asio_wrapper/asio_wrapper.hpp"
#include "gtest/gtest.h"

namespace cppeng {
namespace tcp {

class WritableHandlerImplServer : public WritableHandler {
 public:
  void HandleCallback(std::vector<uint8_t> data,
                      std::shared_ptr<Writable> writable) override {
    // Convert void pointer to string
    std::string received(data.begin(), data.end());
    std::cout << "Server Rx: " << received << std::endl;
    const std::string default_reply = "HTTP/1.1 200 OK\r\n"
                                      "Content-Type: text/html\r\n"
                                      "Connection: close\r\n"
                                      "Content-Length: 28\r\n"
                                      "\r\n"
                                      "<h1>Testing is Awesome!</h1>";
    writable->Write(default_reply);
  }
  void NotifyClosed(std::shared_ptr<Writable> ptr) override {
    std::cout << "Server: Connection closed!" << std::endl;
  }
};

class WritableHandlerImplClient : public WritableHandler {
 public:
  void HandleCallback(std::vector<uint8_t> data,
                      std::shared_ptr<Writable> writable) override {
    // Convert void pointer to string
    std::string received(data.begin(), data.end());
    std::cout << "Client Rx: " << received << std::endl;
    // Assert received request
    EXPECT_TRUE(strcmp(received.c_str(), "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\nContent-Length: 28\r\n\r\n<h1>Testing is Awesome!</h1>") == 0);
    rx_flag_ = true;
  }
  void NotifyClosed(std::shared_ptr<Writable> ptr) override {
    std::cout << "Client: Connection closed!" << std::endl;
  }
  bool rx_flag_{false};
};

TEST(ServerUnitTests, StartUpAndStopServer) {
  WritableHandlerImplServer writable_handler_server;
  // Start a server at port 3000
  Server server(3000, writable_handler_server);
  EXPECT_TRUE(server.Start());
  // We can extend the delay here to increase our time to test the server e.g. via a browser
  std::this_thread::sleep_for(std::chrono::milliseconds(1));
  EXPECT_TRUE(server.Stop());
}

TEST(ServerUnitTests, StartUpAndStopClient) {
  // First we'll start a server
  WritableHandlerImplServer writable_handler_server;
  WritableHandlerImplClient writable_handler_client;
  // Start a server at port 3000
  Server server(3000, writable_handler_server);
  EXPECT_TRUE(server.Start());
  // Start a client which should connect to the port (with timeout of 1000ms)
  Client client("127.0.0.1", 3000, writable_handler_client);
  EXPECT_TRUE(client.Start(1000));
  // Write something to the server
  client.Write("Hello World!");
  Sleep(1);
  // Stop the client and the server
  EXPECT_TRUE(client.Stop());
  EXPECT_TRUE(server.Stop());
  EXPECT_TRUE(writable_handler_client.rx_flag_);
}

}// namespace tcp
}// namespace cppeng