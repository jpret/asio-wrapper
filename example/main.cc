/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper example

    FILE:           example/main.cc
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include<iostream>

#include "interfaces/writable_handler.h"
#include "tcp/server.h"
#include "tcp/client.h"

/**
 * This class implements the WritableHandler interface to handle any callbacks 
   received for the server implementation
 */
class WritableHandlerImplServer : public cppeng::interfaces::WritableHandler {
public:
    void HandleCallback(void* data, int len,
        std::shared_ptr<cppeng::interfaces::Writable> writable) {
        // Convert void pointer to string
        std::string received((uint8_t*)data, (uint8_t*)data + len);
        std::cout << "Server Rx: " << received << std::endl;
        char default_reply[] = "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Connection: close\r\n"
            "Content-Length: 30\r\n"
            "\r\n"
            "<h1>Examples are Awesome!</h1>";
        writable->Write(default_reply, sizeof default_reply);
    }
};

/**
 * This class implements the WritableHandler interface to handle any callbacks
   received for the client implementation
 */
class WritableHandlerImplClient : public cppeng::interfaces::WritableHandler {
public:
    void HandleCallback(void* data, int len,
        std::shared_ptr<cppeng::interfaces::Writable> writable) {
        // Convert void pointer to string
        std::string received((uint8_t*)data, (uint8_t*)data + len);
        std::cout << "Client Rx: " << received << std::endl;
        received_something_ = true;
    }
    bool HasReceivedSomething() const {
        return received_something_;
    }
private:
    bool received_something_{false};
};

int main(int argc, char* argv[]) {
    // Set using namespaces for this scope
    using namespace cppeng::tcp;
    using namespace cppeng::interfaces;
    bool result = false;
    std::cout << "This is an Asio Wrapper Example!" << std::endl;

    // Setup a client and server handler 
    // See the class declarations above
    WritableHandlerImplServer writable_handler_server;
    WritableHandlerImplClient writable_handler_client;

    // Setup the client and server address and ports
    Client client("127.0.0.1", 3000, writable_handler_client);
    Server server(3000, writable_handler_server);

    // Start the server
    if (server.Start()) {
        // Start the client with a timeout of 1000 milliseconds
        // This will now connect to our server
        if (client.Start(1000)) {
            // Write something to the server
            client.Write("Hello World!", strlen("Hello World!"));
            // Wait until we received something
            while (!writable_handler_client.HasReceivedSomething())
                /* Waiting... */;

            // Stop the client
            client.Stop();
            // Set our result flag
            result = true;
        }
        // Stop the server
        server.Stop();
    }
    // Return result
    return result == true ? EXIT_SUCCESS : EXIT_FAILURE;
}