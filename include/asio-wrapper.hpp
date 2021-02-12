/*******************************************************************************
																			  
    COPYRIGHT:      Cpp::Engineer 2021										  

    LICENCE:        MIT                                                       
    PROJECT:        asio-wrapper									              
    DESCRIPTION:    An ASIO wrapper		
    VERSION:        1.0.0

    FILE:           asio-wrapper.hpp                							      
    URL: 	        https://github.com/cppengineer/asio-wrapper		          
															                  
*******************************************************************************/

#ifndef CPPENG_TCP_ASIO_WRAPPER_H_
#define CPPENG_TCP_ASIO_WRAPPER_H_

#include <array>
#include <set>
#include <string>
#include <thread>
#include <queue>

#include "asio.hpp"

namespace cppeng {
namespace tcp {

class Writable {
public:
    virtual void Write(void* data, int len) = 0;
    virtual ~Writable() = default;
};

class WritableHandler {
 public:
    virtual void HandleCallback(void* data, int len,
        std::shared_ptr<Writable>) = 0;
    virtual ~WritableHandler() = default;
};

class IConnectionManager {
 public:
    virtual void Connect(std::shared_ptr<Writable> writable) = 0;
    virtual void Disconnect(std::shared_ptr<Writable> writable) = 0;
};

class Connection : public Writable,
    public std::enable_shared_from_this<Connection> {
 public:
    Connection(asio::io_context& io_context,
        asio::ip::tcp::socket socket,
        tcp::IConnectionManager& connection_manager,
        WritableHandler& writable_handler);
    bool Start();
    void Close();
    void Write(void* data, int len) override;
 private:
    void DoWrite();
    void DoRead();
    tcp::IConnectionManager& connection_manager_;
    WritableHandler& writable_handler_;
    asio::ip::tcp::socket socket_;
    asio::io_context& io_context_;
    std::array<uint8_t, 8192> read_buffer_;
    std::queue<std::pair<int, uint8_t*>> write_queue_;
    bool write_busy_;
};

class ConnectionManager : public Writable,
    public tcp::IConnectionManager {
 public:
    void Connect(std::shared_ptr<Writable> writable) override;

    void Disconnect(std::shared_ptr<Writable> writable) override;

    void Write(void* data, int len) override;
 private:
    std::set<std::shared_ptr<Writable>> writables_;
};


class Connector : public Writable {
 public:
    Connector(asio::io_context& io_context,
        std::string address,
        int port,
        WritableHandler& writable_handler);
    void Write(void* data, int len) override;
    bool IsConnected() const;
 private:
    const std::string address_;
    const int port_;
    ConnectionManager connection_manager_;
    asio::ip::tcp::socket socket_;
    asio::io_context& io_context_;
    WritableHandler& writable_handler_;
    bool connected_;
    void DoConnect(const asio::ip::tcp::resolver::results_type& endpoints);
};


class Acceptor : public Writable {
 public:
    Acceptor(asio::io_context& io_context,
        const asio::ip::tcp::endpoint& endpoint,
        WritableHandler& writable_handler);
    void Write(void* data, int len) override;
 private:
    asio::io_context& io_context_;
    asio::ip::tcp::acceptor acceptor_;
    ConnectionManager connection_manager_;
    WritableHandler& writable_handler_;
    void DoAccept();
};


class Client : public Writable {
 public:
    Client(std::string address, int port,
        WritableHandler& writable_handler);
    bool Start(int timeout_ms);
    bool Stop();
    void Write(void* data, int len) override;
 private:
    const std::string address_;
    int port_;
    asio::io_context io_context_;
    std::unique_ptr<Connector> connector_;
    WritableHandler& writable_handler_;
    std::thread worker_;
};


class Server: public Writable {
 public:
    Server(int port, WritableHandler &writable_handler);
    bool Start();
    bool Stop();
    void Write(void* data, int len) override;
 private:
    asio::io_context io_context_;
    std::unique_ptr<Acceptor> acceptor_;
    WritableHandler& writable_handler_;
    std::thread worker_;
};

} // namespace tcp
} // namespace cppeng

#endif // CPPENG_TCP_ASIO_WRAPPER_H_
