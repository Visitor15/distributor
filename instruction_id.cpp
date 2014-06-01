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
    _uri = new Uri(_internalId, _externalId);
}

long InstructionID::getInternalId() {
    return _internalId;
}

std::string InstructionID::getExternalId() {
    return _externalId;
}

bool InstructionID::canResolveUri() {
    return true;
}

bool InstructionID::executeInstruction(InstructionResponse &response, InstructionData &data) {
    SharedFunction returnFunc;
    if(!_uri->resolve(returnFunc)) {
        return false;
    }

    response = returnFunc.executeFunction(data);


    return true;
}