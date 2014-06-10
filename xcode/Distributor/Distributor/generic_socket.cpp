//
//  generic_socket.cpp
//  Distributor
//
//  Created by Nick C. on 6/9/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "generic_socket.h"

GenericSocket::GenericSocket() : Socket(SOCK_STREAM, IPPROTO_TCP) {
    initialize(SOCK_STREAM, IPPROTO_TCP);
}

GenericSocket::GenericSocket(int socketDesription) : Socket(socketDesription) {
    this->_sockDescriptor = socketDesription;
}

GenericSocket::GenericSocket(int socketType, int protocol) : Socket(socketType, protocol) {
    initialize(socketType, protocol);
}

GenericSocket::GenericSocket(const std::string &destAddr, unsigned short destPort) : Socket(SOCK_STREAM, IPPROTO_TCP) {
    initialize(SOCK_STREAM, IPPROTO_TCP);
    attemptConnect(destAddr, destPort);
}

GenericSocket::~GenericSocket() {

#ifdef WIN32
    closesocket(_sockDescriptor);
#else
    close(_sockDescriptor);
#endif
    _sockDescriptor = -1;
}

void GenericSocket::initialize(int socketType, int protocol) {
#ifdef WIN32
    if (!_isConnected) {
        WORD wVersionRequested;
        WSADATA wsaData;

        wVersionRequested = MAKEWORD(2, 0);              // Request WinSock v2.0
        if (WSAStartup(wVersionRequested, &wsaData) != 0) {  // Load WinSock DLL
            // ERROR
        }
        _isConnected = true;
    }
#endif

    // Make a new socket
    if ((_sockDescriptor = socket(PF_INET, socketType, protocol)) < 0) {
        std::cout << "ERROR INITIALIZING GENERIC SOCKET" << std::endl;
    }
}

std::string GenericSocket::getLocalAddress() {
    unsigned int addr_len = sizeof(_sockAddr_ip4);

    if (getsockname(_sockDescriptor, (sockaddr *) &_sockAddr_ip4, (socklen_t *) &addr_len) < 0) {
        return "ERROR GETTING LOCAL ADDRESS";
    }
    return inet_ntoa(_sockAddr_ip4.sin_addr);
}

unsigned short GenericSocket::getLocalPort() {
    unsigned int addr_len = sizeof(_sockAddr_ip4);

    if (getsockname(_sockDescriptor, (sockaddr *) &_sockAddr_ip4, (socklen_t *) &addr_len) < 0) {
        return 0;
    }
    return ntohs(_sockAddr_ip4.sin_port);
}

bool GenericSocket::setLocalPort(unsigned short localPort) {
    // Bind the socket to its port
    memset(&_sockAddr_ip4, 0, sizeof(_sockAddr_ip4));
    _sockAddr_ip4.sin_family = AF_INET;
    _sockAddr_ip4.sin_addr.s_addr = htonl(INADDR_ANY);
    _sockAddr_ip4.sin_port = htons(localPort);

    if (bind(_sockDescriptor, (sockaddr *) &_sockAddr_ip4, sizeof(sockaddr_in)) < 0) {
        return false;
    }

    return true;
}

bool GenericSocket::setLocalAddressAndPort(const std::string &localAddress, unsigned short localPort) {
    // Get the address of the requested host
    FILL_ADDRESS(localAddress, localPort, _sockAddr_ip4);

    if (bind(_sockDescriptor, (sockaddr *) &_sockAddr_ip4, sizeof(sockaddr_in)) < 0) {
        return false;
    }

    return true;
}

unsigned short GenericSocket::resolveService(const std::string &service, const std::string &protocol) {
    struct servent *serv;        /* Structure containing service information */

    if ((serv = getservbyname(service.c_str(), protocol.c_str())) == NULL)
        return atoi(service.c_str());  /* Service is port number */
    else
        return ntohs(serv->s_port);    /* Found port (network byte order) by name */
}

Socket<GenericSocket>* GenericSocket::acceptConnection() {
    return nullptr;
}

void GenericSocket::cleanUp() {
#ifdef WIN32
    if (WSACleanup() != 0) {
        // ERROR
    }
#endif
}

bool GenericSocket::attemptConnect(const std::string &destinationAddr, unsigned short destinationPort) {
    // Get the address of the requested host
    FILL_ADDRESS(destinationAddr, destinationPort, _destSockAddr_ip4);

    // Try to connect to the given port
    if (connect(_sockDescriptor, (sockaddr *) &_destSockAddr_ip4, sizeof(_destSockAddr_ip4)) < 0) {
        return false;
    }

    return true;
}

bool GenericSocket::sendData(const void* data, int dataLength) {
    if (send(_sockDescriptor, const_cast<void*>(data), dataLength, 0) < 0) {
        return false;
    }
    return true;
}

bool GenericSocket::receiveData(void* data, int dataLength) {

    return false;
}

std::string GenericSocket::getDestinationAddress() {
    return _destAddr;
}

unsigned short GenericSocket::getDestinationPort() {
    return _destPort;
}

