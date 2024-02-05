#ifndef PEERINFO_H
#define PEERINFO_H

#include <string>

struct PeerInfo {
    std::string name;
    std::string ip;
    int port;
    int id;

    PeerInfo(std::string name, std::string ip, int port, int id)
        : name(name), ip(ip), port(port), id(id) {}

    std::string to_string() const {
        return name + " " + ip + ":" + std::to_string(port);
    }
};

#endif // PEERINFO_H
