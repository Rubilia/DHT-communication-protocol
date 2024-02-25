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
