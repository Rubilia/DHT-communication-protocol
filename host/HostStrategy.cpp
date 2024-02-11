#include "HostStrategy.h"
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

void HostStrategy::register_peer(const std::string& manager_ip, int manager_port) {
    // Simulating peer registration
    std::cout << "Registering peer with manager at " << manager_ip << ":" << manager_port << std::endl;

    PeerInfo new_peer("peer1", "127.0.0.1", 27500, 1);
    ring_manager.add_peer(new_peer);
}

void HostStrategy::run() {
    std::cout << "Host running..." << std::endl;
    // Further logic to handle peer communication
}
