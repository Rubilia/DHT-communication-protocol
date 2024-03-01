#include "RingManager.h"
#include <iostream>
#include <map>

std::map<int, std::string> data_store;

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

void RingManager::store_data_in_peer(const std::string& data) {
    int hash_key = std::hash<std::string>{}(data) % peers.size();
    data_store[hash_key] = data;
    std::cout << "Data stored in peer with hash: " << hash_key << std::endl;
}
