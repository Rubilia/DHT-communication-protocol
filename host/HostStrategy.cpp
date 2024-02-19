#include "HostStrategy.h"
#include <iostream>
#include <boost/asio.hpp>
#include <thread>

using boost::asio::ip::udp;

void HostStrategy::register_peer(const std::string& manager_ip, int manager_port) {
    std::cout << "Registering peer with manager at " << manager_ip << ":" << manager_port << std::endl;

    PeerInfo new_peer("peer1", "127.0.0.1", 27500, 1);
    ring_manager.add_peer(new_peer);
}

void HostStrategy::run() {
    std::cout << "Host running..." << std::endl;

    std::thread([&]() {
        boost::asio::io_context io_context;
        udp::socket socket(io_context, udp::endpoint(udp::v4(), 27500));

        while (true) {
            char buffer[1024];
            udp::endpoint sender_endpoint;
            size_t length = socket.receive_from(boost::asio::buffer(buffer), sender_endpoint);
            std::string message(buffer, length);
            std::cout << "Received message: " << message << std::endl;

            if (message.find("setup-dht") == 0) {
                int num_peers = 3; // Simplified for now
                std::cout << "Setting up DHT with " << num_peers << " peers" << std::endl;
                // Setup logic here
            }
        }
    }).detach();

    std::this_thread::sleep_for(std::chrono::seconds(30));
}
