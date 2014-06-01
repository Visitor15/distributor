//
//  generic_response.cpp
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "generic_response.h"

GenericInstructionResponse::GenericInstructionResponse() : InstructionResponse() {
    
}

GenericInstructionResponse::GenericInstructionResponse(InstructionData data) : InstructionResponse(data) {
    
}

GenericInstructionResponse::~GenericInstructionResponse() {
    
}

void GenericInstructionResponse::initialize() {
    
}

void GenericInstructionResponse::setStringData(char* data) {
    _data.setStringData(data);
}