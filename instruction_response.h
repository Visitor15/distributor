//
//  instruction_response.h
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef Distributor_instruction_response_h
#define Distributor_instruction_response_h

#include "instruction_data.h"

class InstructionResponse {
    /* FUNCTIONS */
private:
    
protected:
    
public:
    InstructionResponse() {}
    
    InstructionResponse(InstructionData data) { _data = data; };
    
    ~InstructionResponse() {}

    void initialize() {};
    
    std::string getStringData() { return "TEST"; };
    
    /* VARIABLES */
private:
    
protected:
    InstructionData _data;
    
public:
    
};

#endif
