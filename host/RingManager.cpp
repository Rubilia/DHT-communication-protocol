#include "RingManager.h"
#include <iostream>

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

void RingManager::remove_peer(const std::string& name) {
    peers.erase(std::remove_if(peers.begin(), peers.end(), [&](const PeerInfo& p) { return p.name == name; }), peers.end());
    std::cout << "Peer removed: " << name << std::endl;
}
