//
//  proxy_server.h
//  Distributor
//
//  Created by Nick C. on 6/5/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__proxy_server__
#define __Distributor__proxy_server__

#include <iostream>

#include "network.h"

class ProxyServer {
    /* FUNCTIONS */
private:
    void listenInternal();

protected:

public:
    ProxyServer();

    ~ProxyServer();

    void beginListeningAsync(int port = DEFAULT_LISTEN_PORT);

    bool pingFunction();

    /* VARIABLES */
private:

protected:
    
public:
    
};

#endif /* defined(__Distributor__proxy_server__) */
