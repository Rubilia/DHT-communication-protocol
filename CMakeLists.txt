cmake_minimum_required(VERSION 3.10)
project(DHTProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(host host/Host.cpp host/RingManager.cpp common/PeerInfo.cpp)
add_executable(server server/Server.cpp server/PeerStorage.cpp common/PeerInfo.cpp)
