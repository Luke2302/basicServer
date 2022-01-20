#include <iostream>
#include <sys/socket.h>

using namespace std;

int main(){
    cout << "Server Started";

    //Create Socket socket(int domain, int type, int protocol)
    //Domain types eg AF_INET (IP)  AF_INET6 (IPv6)
    //Type of service SOCK_STREAM (virtual circuit service), SOCK_DGRAM (datagram service)
    //Protocol- Useful in cases where some families may have more than one protocol to support a given type of service.
    //Use AF_NET for IPv4 and  SOCK_STREAM for TCP
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_fd < 0){
        cerr << "Socket Creation Failed";
        return 1;
    }

    cout << "Socket Created Successfully";
    return 0;
}