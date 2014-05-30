//
//  instruction_id.cpp
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "instruction_id.h"

InstructionID::InstructionID() {
    
}

InstructionID::~InstructionID() {
    
}

InstructionID::InstructionID(long numId, std::string strId) {
    _externalId = strId;
    _internalId = numId;
}

long InstructionID::getInternalId() {
    return _internalId;
}

bool InstructionID::fetchInstruction(InstructionResponse &data) {
    return true;
}