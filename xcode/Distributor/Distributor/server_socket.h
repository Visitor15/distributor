//
//  server_socket.h
//  Distributor
//
//  Created by Nick C. on 6/9/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__server_socket__
#define __Distributor__server_socket__

#include <iostream>
#include <thread>

#include "generic_socket.h"

class ServerSocket : public GenericSocket {
    /* FUNCTIONS */
private:
    void setListeningInternal(int listenLength);

    void handleClientInternal(Socket* incomingSocket);

protected:

    virtual Socket* acceptConnection();

public:

    ServerSocket();

    ~ServerSocket();

    void beginListening();

    void stopListening();

    /* VARIABLES */
private:
    bool _isRunning;

protected:

public:

};

#endif /* defined(__Distributor__server_socket__) */
