#include "Server.h"
#include <iostream>

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

            if (message.find("register") == 0) {
                // Extract peer info and register
                std::string peer_name = "peer1"; // Simplified for now
                peer_storage.register_peer(PeerInfo(peer_name, sender_endpoint.address().to_string(), sender_endpoint.port(), 1));
                std::cout << "Peer registered: " << peer_name << std::endl;
            }

            handle_receive();
        }
    });
}
