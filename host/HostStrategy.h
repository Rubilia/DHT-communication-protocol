#ifndef HOSTSTRATEGY_H
#define HOSTSTRATEGY_H

#include "RingManager.h"
#include "common/PeerInfo.h"
#include <string>

class HostStrategy {
private:
    RingManager ring_manager;

public:
    void register_peer(const std::string& manager_ip, int manager_port);
    void run();
};

#endif // HOSTSTRATEGY_H
