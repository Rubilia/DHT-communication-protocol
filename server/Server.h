#ifndef SERVER_H
#define SERVER_H

#include "PeerStorage.h"
#include <boost/asio.hpp>
#include <string>

class Server {
public:
    Server(int port);
    void run();

private:
    PeerStorage peer_storage;
    boost::asio::io_context io_context;
    boost::asio::ip::udp::socket socket;

    void handle_receive();
};

#endif // SERVER_H
