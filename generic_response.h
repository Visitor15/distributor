//
//  generic_response.h
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__generic_response__
#define __Distributor__generic_response__

#include <iostream>

#include "instruction_response.h"

class GenericInstructionResponse : public InstructionResponse {
    /* FUNCTIONS */
private:
    
protected:
    
public:
    GenericInstructionResponse();
    
    GenericInstructionResponse(InstructionData data);
    
    ~GenericInstructionResponse();

    void initialize();

    void serialize();

    void deSerialize();
    
    /* VARIABLES */
private:
    
protected:
    
public:
    
};

#endif /* defined(__Distributor__generic_response__) */
