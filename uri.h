//
//  uri.h
//  Distributor
//
//  Created by Nick C. on 5/29/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__uri__
#define __Distributor__uri__

#include <iostream>

enum EURI_SCHEME_TYPE {
    LOCAL = 0
};

class Uri {
    /* FUNCTIONS */
private:
    
protected:
    
public:
    Uri();
    
    ~Uri();
    
    void initialize();
    
    bool resolve(char* buffer, unsigned int length);
    
    /* VARIABLES */
private:
    
protected:
    
public:
};

#endif /* defined(__Distributor__uri__) */
