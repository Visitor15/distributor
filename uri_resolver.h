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

class Uri;      // Forward declaration for Uri*

class UriResolver {
    /* FUNCTIONS */
private:
    bool resolveUriInternal();

protected:

public:
    UriResolver();

    UriResolver(Uri* uriPtr);

    ~UriResolver();

    void initialize();

    bool resolve(char* buffer = nullptr, unsigned int length = 0);

    /* VARIABLES */
private:
    Uri* _internalUriPtr;

protected:

public:

};

#endif /* defined(__Distributor__uri_resolver__) */
