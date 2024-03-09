#include "Server.h"
#include <iostream>
#include <boost/system/error_code.hpp>

using boost::asio::ip::udp;

Server::Server(int port) : socket(io_context, udp::endpoint(udp::v4(), port)) {}

void Server::run() {
    std::cout << "Server running..." << std::endl;
    handle_receive();
    io_context.run();
}

void Server::handle_receive() {
    char buffer[1024];
    udp::endpoint sender_endpoint;
    socket.async_receive_from(boost::asio::buffer(buffer), sender_endpoint,
                              [&](const boost::system::error_code& error, std::size_t length) {
        if (!error) {
            std::string message(buffer, length);
            std::cout << "Received message: " << message << std::endl;

            if (message.find("teardown-complete") == 0) {
                std::cout << "Teardown completed successfully." << std::endl;
            } else if (message.find("teardown-dht") == 0) {
                std::cout << "Tearing down DHT..." << std::endl;
                // Send confirmation
                socket.send_to(boost::asio::buffer("teardown-complete"), sender_endpoint);
            }

            handle_receive();
        } else {
            std::cerr << "Error receiving data: " << error.message() << std::endl;
        }
    });
}
