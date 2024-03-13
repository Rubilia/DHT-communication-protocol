#include "RingManager.h"
#include <iostream>
#include <boost/asio.hpp>
#include <unordered_map>

std::unordered_map<std::string, PeerInfo> peer_lookup; // Optimization

void RingManager::add_peer(const PeerInfo& peer) {
    peers.push_back(peer);
    peer_lookup[peer.name] = peer; // Cache peer info
    std::cout << "Peer added: " << peer.to_string() << std::endl;
}

void RingManager::update_neighbors(int peer_id) {
    this->peer_id = peer_id;
    std::cout << "Updated neighbors for peer: " << peer_id << std::endl;
}

void RingManager::clear_peers() {
    peers.clear();
    peer_lookup.clear();
    std::cout << "All peers cleared from the ring" << std::endl;
}

PeerInfo RingManager::get_peer_by_name(const std::string& name) {
    if (peer_lookup.find(name) != peer_lookup.end()) {
        return peer_lookup[name];
    }
    throw std::runtime_error("Peer not found");
}
