#include <iostream>
#include <boost/asio.hpp>

//Add namespace here? -> Only using small number of names from std
//ip:::tcp
//std::string
//std::cout
//std::endl

std::string read(boost::asio::ip::tcp::socket & socket);
void send(boost::asio::ip::tcp::socket & socket, const std::string & message);

int main()
{

    //Add error code?

    boost::system::error_code ec;

    //create asio instance 

    boost::asio::io_context context;

    //create a socket

    boost::asio::ip::tcp::socket socket(context);

    //create an endpoint -> This is the address of where we want to connect to 
    //end point takes ip address and port number as arguments. 

    //ip and port number should equal that of server we wish to connect to
    //can pass error code in as arg to make_address

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("127.0.0.1", ec), 1234);

    //tell the socket to attempt to connect to the specified endpoint
    //can pass error code in as arg to connect

    socket.connect(endpoint, ec);

    if(!ec)
    {
        std::cout << "Connected Successfully " << std::endl;
    }
    else
    {
        std::cout << "Failed to Connect to Endpoint: \n" << ec.message() << std::endl;
    }

    //Send message to server 

    send(socket, "Client 1");
    std::cout << "Message Sent From Client To Server" << std::endl;

    //Read message response from server

    std::string message = read(socket);
    std::cout << message << std::endl;


    return 0;
}

std::string read(boost::asio::ip::tcp::socket & socket)
{
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket, buffer, "\n");
    std::string data = boost::asio::buffer_cast<const char*>(buffer.data());
    return data;
}

void send(boost::asio::ip::tcp::socket & socket, const std::string & message)
{
    const std::string msg = message + "\n";
    boost::asio::write(socket, boost::asio::buffer(msg));
}