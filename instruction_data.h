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

#include "generic_data.h"

class InstructionData : GenericData<InstructionData> {
    /* FUNCTIONS */
private:
    char* getDataSecure();
    
protected:
    
public:
    InstructionData();

    ~InstructionData();

    bool doAuthentication();

    void setStringData(char* data);

    std::string getStringData();

    void serialize(std::ostream &stream);

    void deSerialize(std::ostream &stream);
    
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
