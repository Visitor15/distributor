//
//  uri_resolver.h
//  Distributor
//
//  Created by Nick C. on 5/30/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__uri_resolver__
#define __Distributor__uri_resolver__

#include <iostream>

class UriResolver {
    /* FUNCTIONS */
private:

protected:

public:
    UriResolver();

    ~UriResolver();

    void initialize();

    bool resolve(char* buffer, unsigned int length);

    /* VARIABLES */
private:

protected:

public:

};

#endif /* defined(__Distributor__uri_resolver__) */
