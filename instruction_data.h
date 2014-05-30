//
//  instruction_data.h
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__instruction_data__
#define __Distributor__instruction_data__

#include <iostream>

template <class T> class GenericData {
    /* FUNCTIONS */
private:
    
protected:
    
public:
    
    /* VARIABLES */
private:
    
protected:
    
public:
    char* getData();
};

class SecureInstructionData : GenericData<SecureInstructionData> {
    /* FUNCTIONS */
private:
    char* getDataSecure();
    
protected:
    
public:
    bool doAuthentication();
    
    char* getData() {
        if(doAuthentication()) {
            return getDataSecure();
        }
        else {
            return NULL;
        }
    }
    
    /* VARIABLES */
private:
    
protected:
    
public:
    
};

class InstructionData : GenericData<InstructionData> {
    /* FUNCTIONS */
private:
    char* getDataSecure();
    
protected:
    
public:
    bool doAuthentication();
    
    char* getData() {
        if(doAuthentication()) {
            return getDataSecure();
        }
        else {
            return NULL;
        }
    }
    
    /* VARIABLES */
private:
    
protected:
    
public:
    
};

#endif /* defined(__Distributor__instruction_data__) */
