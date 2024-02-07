#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class Host {
public:
    void start() {
        boost::asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 0));

        std::string message = "Hello, peer!";
        udp::resolver resolver(io_context);
        udp::resolver::results_type endpoints = resolver.resolve(udp::v4(), "localhost", "27600");

        socket.send_to(boost::asio::buffer(message), *endpoints.begin());
        std::cout << "Message sent: " << message << std::endl;
    }
};

int main() {
    Host host;
    host.start();
    return 0;
}
