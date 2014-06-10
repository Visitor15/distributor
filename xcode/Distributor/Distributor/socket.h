//
//  socket.h
//  Distributor
//
//  Created by Nick C. on 6/9/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#pragma once

#ifndef __Distributor__socket__
#define __Distributor__socket__

#include <iostream>

#ifdef WIN32

#include <winsock.h>

#else

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#endif


template <class T> class Socket {
    /* FUNCTIONS */
private:
    Socket(const Socket &sock);
    void operator=(const Socket &sock);

protected:
    // Function to fill in address structure given an address and port
    static void FILL_ADDRESS(const std::string &address, unsigned short port,
                         sockaddr_in &addr) {
        memset(&addr, 0, sizeof(addr));  // Zero out address structure
        addr.sin_family = AF_INET;       // Internet address

        hostent *host;  // Resolve name
        if ((host = gethostbyname(address.c_str())) == NULL) {
            // strerror() will not work for gethostbyname() and hstrerror()
            // is supposedly obsolete
//            throw SocketException("Failed to resolve name (gethostbyname())");
        }
        addr.sin_addr.s_addr = *((unsigned long *) host->h_addr_list[0]);
        
        addr.sin_port = htons(port);     // Assign port in network byte order
    }

    Socket(int type, int protocol) {};

    Socket(int sockDesc) {};

    virtual ~Socket() {};


public:

    virtual std::string getLocalAddress() { return ""; };

    virtual unsigned short getLocalPort() { return 0; };

    virtual bool setLocalPort(unsigned short localPort) { return false; };

    virtual bool setLocalAddressAndPort(const std::string &localAddress,
                                        unsigned short localPort = 0) { return false; };

    virtual unsigned short resolveService(const std::string &service,
                                          const std::string &protocol = "tcp") { return 0; };

    virtual void cleanUp() {};

    /* VARIABLES */
private:
protected:
    sockaddr_in _sockAddr_ip4;

    sockaddr_in _destSockAddr_ip4;

    sockaddr_in6 _sockAddr_ip6;

    sockaddr_in6 _destSockAddr_ip6;

    std::string _localHostName;

    std::string _destAddr;

    int _sockDescriptor;

    int _localPort;

    int _destPort;

    bool _isConnected;

public:
};

#endif /* defined(__Distributor__socket__) */
