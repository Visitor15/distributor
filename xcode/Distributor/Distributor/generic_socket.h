//
//  generic_socket.h
//  Distributor
//
//  Created by Nick C. on 6/9/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__generic_socket__
#define __Distributor__generic_socket__

#include <iostream>

#include "socket.h"

class GenericSocket : public Socket<GenericSocket> {
    /* FUNCTIONS */
private:
    void initialize(int socketType, int protocol);

protected:
public:
    GenericSocket();

    GenericSocket(int socketDesription);

    GenericSocket(int socketType, int protocol);

    GenericSocket(const std::string &destAddress, unsigned short destPort);

    ~GenericSocket();

    virtual std::string getLocalAddress();

    virtual unsigned short getLocalPort();

    virtual bool setLocalPort(unsigned short localPort);

    virtual bool setLocalAddressAndPort(const std::string &localAddress,
                                        unsigned short localPort = 0);

    virtual unsigned short resolveService(const std::string &service,
                                          const std::string &protocol = "tcp");

    virtual void cleanUp();

    virtual bool attemptConnect(const std::string &destinationAddr, unsigned short destinationPort);

    virtual bool sendData(const void* data, int dataLength);

    virtual bool receiveData(void* data, int dataLength);

    virtual std::string getDestinationAddress();

    virtual unsigned short getDestinationPort();

    virtual Socket* acceptConnection();

    /* VARIABLES */
private:
protected:
public:

};

#endif /* defined(__Distributor__generic_socket__) */
