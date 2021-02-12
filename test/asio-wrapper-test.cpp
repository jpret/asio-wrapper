/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper
    VERSION:        1.0.0

    FILE:           asio-wrapper-test.cpp
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include "gtest/gtest.h"
#include "asio-wrapper.hpp"

namespace cppeng {
namespace tcp {

class WritableHandlerImplServer : public WritableHandler {
public:
    void HandleCallback(void* data, int len,
                        std::shared_ptr<Writable> writable) {
        // Convert void pointer to string
        std::string received((uint8_t*)data, (uint8_t*)data + len);
        std::cout << "Server Rx: " << received << std::endl;
        char default_reply[] = "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"
            "Content-Length: 28\r\n"
            "\r\n"
            "<h1>Testing is Awesome!</h1>";
        writable->Write(default_reply, sizeof default_reply);
    }
};

class WritableHandlerImplClient : public WritableHandler {
public:
    void HandleCallback(void* data, int len,
        std::shared_ptr<Writable> writable) {
        // Convert void pointer to string
        std::string received((uint8_t*)data, (uint8_t*)data + len);
        std::cout << "Client Rx: " << received << std::endl;
        // Assert received request
        EXPECT_TRUE(strcmp(received.c_str(), "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\nContent-Length: 28\r\n\r\n<h1>Testing is Awesome!</h1>")==0);
        rx_flag_ = true;
    }
    bool rx_flag_{ false };
};

TEST(ServerUnitTests, StartUpServer) {
    WritableHandlerImplServer writable_handler_server;
    // Start a server at port 3000
    Server server(3000, writable_handler_server);
    EXPECT_TRUE(server.Start());
    // We can extend the delay here to increase our time to test the server e.g. via a browser
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    EXPECT_TRUE(server.Stop());
}

TEST(ServerUnitTests, StartUpClient) {
    // First we'll start a server
    WritableHandlerImplServer writable_handler_server;
    WritableHandlerImplClient writable_handler_client;
    // Start a server at port 3000
    Server server(3000, writable_handler_server);
    EXPECT_TRUE(server.Start());
    // Start a client which should connect to the port
    Client client("127.0.0.1", 3000, writable_handler_client);
    EXPECT_TRUE(client.Start(1000));
    // Write something to the server
    client.Write("Hello World!", strlen("Hello World!"));
    Sleep(1);
    // Stop the client and the server
    EXPECT_TRUE(client.Stop());
    EXPECT_TRUE(server.Stop());
    EXPECT_TRUE(writable_handler_client.rx_flag_);
}

} // namespace tcp
} // namespace cppeng