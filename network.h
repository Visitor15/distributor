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
//    virtual void initialize() = 0;

public:

    TCPSocket();

    ~TCPSocket();

    virtual void setPort(unsigned int port) = 0;

//    virtual bool setAddress(std::string addr) = 0;

    virtual bool connectTo() = 0;

    virtual bool sendData(const void* buf, int length) = 0;

    virtual bool receiveData(void* buf, int length) = 0;

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
    virtual void initialize() = 0;

public:

    UDPSocket();

    ~UDPSocket();

    virtual void setPort(unsigned int port) = 0;

    virtual bool setAddress(std::string addr) = 0;

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
