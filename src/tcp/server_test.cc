/*******************************************************************************

    COPYRIGHT:      Cpp::Engineer 2021

    LICENCE:        MIT
    PROJECT:        asio-wrapper
    DESCRIPTION:    An ASIO wrapper

    FILE:           tcp/client.cc
    URL: 	        https://github.com/cppengineer/asio-wrapper

*******************************************************************************/

#include "gtest/gtest.h"
#include "interfaces/writable_handler.h"
#include "tcp/server.h"

namespace cppeng {
namespace tcp {

class WritableHandlerImpl : public interfaces::WritableHandler {
public:
    void HandleCallback(void* data, int len,
                        std::shared_ptr<interfaces::Writable> writable) {
        for (int i = 0; i < len; i++) {
            uint8_t c = (uint8_t)(data);
            std::cout << c;
        }
        std::cout << std::endl;
    }
};

TEST(ServerUnitTests, StartServer) {
    WritableHandlerImpl writable_handler;
    Server server(3000, writable_handler);
    server.Start();
}

} // namespace tcp
} // namespace cppeng