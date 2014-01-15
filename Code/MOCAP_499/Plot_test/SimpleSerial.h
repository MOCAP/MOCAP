#include <boost/asio.hpp>
#include <string>

using namespace std;

class SimpleSerial
{
public:
	  SimpleSerial(std::string port, unsigned int baud_rate);
	  void writeString(std::string s);
	  std::string readLine();


private:
	boost::asio::io_service io;
    boost::asio::serial_port serial;
};