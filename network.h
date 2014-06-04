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
