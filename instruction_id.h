//
//  instruction_id.h
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__instruction_id__
#define __Distributor__instruction_id__

#include <iostream>

#include "instruction_response.h"
#include "uri.h"

class Uri;

class InstructionID {
    /* FUNCTIONS */
private:
    
protected:
    
public:
    InstructionID();
    
    InstructionID(long, std::string);
    
    ~InstructionID();

    bool canResolveUri();
    
    bool executeInstruction(InstructionResponse&);
    
    long getInternalId();

    std::string getExternalId();
    
    /* VARIABLES */
private:
    Uri* _uri;

    std::string _uriStr;
    
    std::string _externalId;
    
    long _internalId;
    
protected:
    
public:
    
};

#endif /* defined(__Distributor__instruction_id__) */
