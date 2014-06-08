//
//  tcp_socket.cpp
//  Distributor
//
//  Created by Nick C. on 6/5/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "network.h"

TCPSocket::TCPSocket() : Socket<TCPSocket>() {
    _isConnected = true;
    _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

TCPSocket::TCPSocket(int socket) : Socket<TCPSocket>(socket) {
    this->_socket = socket;
}

TCPSocket::TCPSocket(std::string address, int port) : Socket<TCPSocket>() {
    _isConnected = false;
    _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    setAddress(address, port, _sockAddr);
    connectTo();
}

TCPSocket::~TCPSocket() {
}

void TCPSocket::setPort(unsigned int port) {
    _port = port;
    setLocalPort(_port);
}

//bool TCPSocket::setAddress(std::string addr) {
//    memset(&_sockAddr, 0, sizeof(_sockAddr));
//    _sockAddr.sin_family = AF_INET;
//
//    _hostName = gethostbyname(addr.c_str());
//    if(_hostName == NULL) {
//        return false;
//    }
//
//    initialize();
//
//    return true;
//}

//void TCPSocket::initialize() {
//    _isConnected = false;
//    _sockAddr.sin_addr.s_addr = *((unsigned int*)_hostName->h_addr_list[0]);
//    _sockAddr.sin_port = htons(_port);
//}

bool TCPSocket::connectTo() {
    if(connect(_socket, (sockaddr*) &_sockAddr, sizeof(_sockAddr)) < 0) {
        return false;
    }

    _isConnected = true;

    return true;
}

bool TCPSocket::sendData(const void* buf, int length) {
    if(!_isConnected) {
        return false;
    }

    if(send(_socket, buf, length, 0) < 0) {
        return false;
    }

    return true;
}

bool TCPSocket::receiveData(void* buf, int length) {
    if(!_isConnected) {
        return false;
    }

    if(recv(_socket, buf, length, 0) < 0) {
        return false;
    }

    std::cout << "Listening socket received: " << buf << std::endl;

    return true;
}

bool TCPSocket::setSocketListening(unsigned int queueLength) {
    if(listen(_socket, queueLength) < 0) {
        return false;
    }

    return true;
}

TCPSocket* TCPSocket::accept() {
    int newConnection;
    if((newConnection = ::accept(_socket, NULL, 0)) < 0) {
        return nullptr;
    }

    return new TCPSocket(newConnection);
}