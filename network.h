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

static unsigned int DEFAULT_LISTEN_PORT = 11235;

static std::string DEFAULT_HOSTNAME = "localhost";

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
