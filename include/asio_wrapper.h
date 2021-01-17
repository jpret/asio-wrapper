/******************************************************************************/
/*																			  */
/* COPYRIGHT Cpp::Engineer 2020												  */	
/* LICENCE: MIT                                                               */	
/* title:	An ASIO wrapper									                  */
/* project: asio-wrapper									                  */
/* file:    asio_wrapper.h									                  */	
/* url: 	https://github.com/cppengineer/asio-wrapper		                  */
/*															                  */
/******************************************************************************/


namespace cppeng {
namespace tcp {

class Writable {
 public:
  void Write(void* data, int len) = 0;
  virtual ~Writable = default;
};

class WritableHandler {
 public:
  void HandleCallback(void* data, int len, std::shared_ptr<Writable>) = 0;
  virtual ~WritableHandler = default;
};

class Server: public Writable {
 public:
  bool Initialise(int port, WritableHandler &writable_handler);
  bool Start();
  bool Stop();
  void Write(char* data, int len) override;
};

class Client: public Writable {
 public:
  bool Initialise(int port, const std::string& address, WritableHandler& writable_handler);
  bool Start(int connect_timeout);
  bool Stop();
  void Write(char* data, int len) override;
};

} // namespace tcp
} // namespace cppeng

/******************************************************************************/
/*								   END OF FILE								  */
/******************************************************************************/