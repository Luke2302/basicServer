#include <iostream>
#include <boost/asio.hpp>


//Add namespace here? -> Only using small number of names from std
//ip:::tcp
//std::string
//std::cout
//std::endl

std::string read(boost::asio::ip::tcp::socket & socket);
void send(boost::asio::ip::tcp::socket & socket, const std::string & message);