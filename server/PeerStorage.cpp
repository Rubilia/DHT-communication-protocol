#include "PeerStorage.h"
#include <iostream>

void PeerStorage::register_peer(const PeerInfo& peer) {
    peers.push_back(peer);
    std::cout << "Peer registered: " << peer.to_string() << std::endl;
}

void PeerStorage::unregister_peer(const std::string& name) {
    peers.erase(std::remove_if(peers.begin(), peers.end(), [&](const PeerInfo& p) { return p.name == name; }), peers.end());
    std::cout << "Peer unregistered: " << name << std::endl;
}

std::vector<PeerInfo> PeerStorage::get_peers() const {
    return peers;
}
