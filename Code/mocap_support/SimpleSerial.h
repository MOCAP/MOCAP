#ifndef MOCAP_SIMPLE_SERIAL
#define MOCAP_SIMPLE_SERIAL

#include <boost/asio.hpp>
#include <string>

namespace mocap_support{
	class SimpleSerial
	{
	public:
		  SimpleSerial(std::string port, unsigned int baud_rate);
		  void writeString(std::string s);
		  std::string readLine();


	private:
		int connection_status;
		boost::asio::io_service io;
		boost::asio::serial_port serial;
	};
}
mocap_support::SimpleSerial::SimpleSerial(std::string port, unsigned int baud_rate)
: io(), serial(io,port)
{
    serial.set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
	connection_status = 1;
}


void mocap_support::SimpleSerial::writeString(std::string s)
{
    boost::asio::write(serial,boost::asio::buffer(s.c_str(),s.size()));
}

std::string mocap_support::SimpleSerial::readLine()
{
    //Reading data char by char, code is optimized for simplicity, not speed
    using namespace boost;
    char c;
    std::string result;
    for(;;)
    {
        asio::read(serial,asio::buffer(&c,1));
        switch(c)
        {
            case '\r':
                break;
            case '\n':
                return result;
            default:
                result+=c;
        }
    }
}



#endif