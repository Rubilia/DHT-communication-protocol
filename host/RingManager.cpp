#include "RingManager.h"
#include <iostream>
#include <boost/asio.hpp>

void RingManager::add_peer(const PeerInfo& peer) {
    peers.push_back(peer);
    std::cout << "Peer added: " << peer.to_string() << std::endl;
}

void RingManager::update_neighbors(int peer_id) {
    this->peer_id = peer_id;
    std::cout << "Updated neighbors for peer: " << peer_id << std::endl;
}

void RingManager::clear_peers() {
    peers.clear();
    std::cout << "All peers cleared from the ring" << std::endl;
}

void RingManager::send_message_to_next_peer(const std::string& message) {
    if (peers.size() < 2) {
        std::cout << "Not enough peers in the ring to pass the message." << std::endl;
        return;
    }

    boost::asio::io_context io_context;
    boost::asio::ip::udp::socket socket(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::v4(), 0));

    PeerInfo next_peer = peers[(peer_id + 1) % peers.size()];
    boost::asio::ip::udp::resolver resolver(io_context);
    auto endpoints = resolver.resolve(next_peer.ip, std::to_string(next_peer.port));

    socket.send_to(boost::asio::buffer(message), *endpoints.begin());
    std::cout << "Message passed to " << next_peer.to_string() << std::endl;
}
