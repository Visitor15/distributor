//
//  network.h
//  Distributor
//
//  Created by Nick C. on 5/30/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__network__
#define __Distributor__network__

#include <iostream>

#include "sockets.h"
#include "instruction_response.h"

static const unsigned int DEFAULT_LISTEN_PORT = 11235;

static const std::string DEFAULT_HOSTNAME = "localhost";

static const std::string DEFAULT_USER = "user";

enum ESCHEME {
    ELOCAL           = 0,
    EHTTP            = 1,
    EHTTPS           = 2,
    EFTP             = 3,
    EDIRECT_CONNECT  = 4
};

class SCHEMES {
public:
    inline static std::string LOCAL() {
        return "local";
    }

    inline static std::string LOCAL_NETWORK() {
        return "local_net";
    }

    inline static std::string INTERNET() {
        return "net";
    }
    
    inline static std::string DIRECT_CONNECT() {
        return "direct";
    }
};

/***************************************************************************************************
 *  CLASS
 **************************************************************************************************/
class TCPSocket : public Socket<TCPSocket> {
    /* FUNCTIONS */
private:

protected:

public:

    TCPSocket();

    TCPSocket(int socket);

    TCPSocket(std::string address, int port);

    ~TCPSocket();

    virtual void setPort(unsigned int port);

    virtual bool connectTo();

    virtual bool sendData(const void* buf, int length);

    virtual bool receiveData(void* buf, int length);

    virtual bool setSocketListening(unsigned int port);

    virtual TCPSocket* accept();

    /* VARIABLES */
private:

protected:

public:
};

/***************************************************************************************************
 *  CLASS
 **************************************************************************************************/
class UDPSocket : public Socket<UDPSocket> {
    /* FUNCTIONS */
private:

protected:

public:

    UDPSocket();

    ~UDPSocket();

    virtual void setPort(unsigned int port);

    virtual bool connectTo();

    virtual bool sendData(const void* buf, int length);

    virtual bool receiveData(void* buf, int length);

    virtual bool setSocketListening(unsigned int port);

    /* VARIABLES */
private:

protected:

public:
};

/***************************************************************************************************
 *  CLASS
 **************************************************************************************************/
class Network {
    /* FUNCTIONS */
private:
    static InstructionResponse MY_SHARED_FUNCTION(InstructionData data);

protected:

public:
    Network();

    ~Network();

    /* VARIABLES */
private:

protected:

public:

};

#endif /* defined(__Distributor__network__) */
