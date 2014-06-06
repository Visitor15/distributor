//
//  sockets.h
//  Distributor
//
//  Created by Nick C. on 6/5/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef Distributor_sockets_h
#define Distributor_sockets_h

#ifdef WIN32
#include <winsock.h>         // For socket(), connect(), send(), and recv()
typedef int socklen_t;
typedef char raw_type;       // Type used for raw data on this platform
#else
#include <sys/types.h>       // For data types
#include <sys/socket.h>      // For socket(), connect(), send(), and recv()
#include <netdb.h>           // For gethostbyname()
#include <arpa/inet.h>       // For inet_addr()
#include <unistd.h>          // For close()
#include <netinet/in.h>      // For sockaddr_in
typedef void raw_type;       // Type used for raw data on this platform
#endif

/***************************************************************************************************
 *  TEMPLATE CLASS
 **************************************************************************************************/
template <class T> class Socket {
    /* FUNCTIONS */
private:

protected:
    bool setAddress(std::string addrStr, unsigned int port, sockaddr_in &addr) {
        _isConnected = false;
        _port = port;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;

        _hostName = gethostbyname(addrStr.c_str());
        if(_hostName == NULL) {
            return false;
        }

        _sockAddr.sin_addr.s_addr = *((unsigned int*)_hostName->h_addr_list[0]);
        _sockAddr.sin_port = htons(_port);
        
        return true;
    }

    bool setLocalPort(unsigned short localPort) {
        sockaddr_in localAddr;
        memset(&localAddr, 0, sizeof(localAddr));
        localAddr.sin_family = AF_INET;
        localAddr.sin_addr.s_addr = htonl(INADDR_ANY);
        localAddr.sin_port = htons(localPort);


        if (bind(_socket, (sockaddr *) &localAddr, sizeof(sockaddr_in)) < 0) {
            return false;
        }

        return true;
    }

    bool setLocalAddressAndPort(const std::string &localAddress, unsigned int localPort) {
        sockaddr_in _localAddr;
        setAddress(localAddress, localPort, _localAddr);

        if(bind(_socket, (sockaddr*) &_localAddr, sizeof(sockaddr_in)) < 0) {
            return false;
        }

        return true;
    }

public:
    Socket() {};

    Socket(int socket) {
        _socket = socket;
    }

    virtual ~Socket() {
#ifdef WIN32
        closesocket(_socket);
#else
        close(_socket);
#endif
        _socket = -1;
    };

    virtual void setPort(unsigned int port) = 0;

//    virtual bool setAddress(std::string addr) = 0;

    virtual bool connectTo() = 0;

    virtual bool sendData(const void* buf, int length) = 0;

    virtual bool receiveData(void* buf, int length) = 0;

    virtual bool setSocketListening(unsigned int port) = 0;

    /* VARIABLES */
private:

protected:
    int _socket;

    sockaddr_in _sockAddr;

    hostent* _hostName;

    unsigned int _port;

    bool _isConnected;

public:
    
};

#endif
