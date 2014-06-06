//
//  tcp_socket.cpp
//  Distributor
//
//  Created by Nick C. on 6/5/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "network.h"

TCPSocket::TCPSocket() {
    _isConnected = false;
}

TCPSocket::~TCPSocket() {

}

void TCPSocket::setPort(unsigned int port) {
    _port = port;
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
    _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(connect(_socket, (sockaddr*) &_sockAddr, sizeof(_sockAddr)) < 0) {
        return false;
    }

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

    return true;
}