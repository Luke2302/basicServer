#include <iostream>
#include <boost/asio.hpp>

#include "server.h"


//Add namespace here? -> Only using small number of names from std
//ip:::tcp
//std::string
//std::cout
//std::endl

int main()
{
    //create asio instance 

    boost::asio::io_context context; 

    //create a socket 

    boost::asio::ip::tcp::socket socket(context);

    //create an endpoint -> this is where the client will be connecting to hosted locally

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 1234);  
    
    //listen for a connection, with acceptor 

    boost::asio::ip::tcp::acceptor acceptor(context, endpoint);

    //Wait and accept connection

    acceptor.accept(socket);

    //Read message from client 

    std::string message = read(socket);
    std::cout << message << std::endl;

    //Send message to client 

    send(socket, "Server 2");

    std::cout << "Message Sent From Server to Client";

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