#ifndef PEERSTORAGE_H
#define PEERSTORAGE_H

#include "common/PeerInfo.h"
#include <vector>
#include <algorithm>

class PeerStorage {
private:
    std::vector<PeerInfo> peers;

public:
    void register_peer(const PeerInfo& peer);
    void unregister_peer(const std::string& name);
    std::vector<PeerInfo> get_peers() const;
};

#endif // PEERSTORAGE_H
