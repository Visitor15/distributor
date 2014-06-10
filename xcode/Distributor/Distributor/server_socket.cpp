//
//  server_socket.cpp
//  Distributor
//
//  Created by Nick C. on 6/9/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "network.h"
#include "server_socket.h"

ServerSocket::ServerSocket() : GenericSocket(SOCK_STREAM, IPPROTO_TCP){
    setLocalAddressAndPort("127.0.0.1", DEFAULT_LISTEN_PORT);
}

ServerSocket::~ServerSocket() {

}

void ServerSocket::beginListening() {
        new std::thread([&]() {
            std::cout << "Server listening in background thread." << std::endl;
            setListeningInternal(50);

            return 0;
        });
}

void ServerSocket::stopListening() {
    _isRunning = false;
}

void ServerSocket::setListeningInternal(int listeningLength) {
    _isRunning = true;
    if(listen(_sockDescriptor, 1) < 0) {
        std::cout << "SERVER FAILED TO LISTEN" << std::endl;
        return;
    }
    do {
        handleClientInternal(acceptConnection());
    } while(_isRunning);
}

Socket<GenericSocket>* ServerSocket::acceptConnection() {
    int newConnSD;
    if ((newConnSD = accept(_sockDescriptor, NULL, 0)) < 0) {
//        std::cout << "No connections found. Sleeping for 50ms." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        return nullptr;
    }
        std::cout << "Found some kind of connection..." << std::endl;


    return new GenericSocket(newConnSD);
}

void ServerSocket::handleClientInternal(Socket* incomingSocket) {
    if(incomingSocket != nullptr) {
        std::cout << "Received client request." << std::endl;
    }
}