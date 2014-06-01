//
//  message_executor.cpp
//  Distributor
//
//  Created by Nick C. on 6/1/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "message_executor.h"

SharedFunction* mySharedFunc;

MessageExecutor::MessageExecutor() {
    initialize();
}

MessageExecutor::~MessageExecutor() {

}

void MessageExecutor::initialize() {
    mySharedFunc = new SharedFunction("TestSharedFunction3", MessageExecutor::PRINT_MESSAGE);
    _instructionId = VManager::GET_INSTANCE().registerSharedFunction(*mySharedFunc);
}

InstructionResponse MessageExecutor::PRINT_MESSAGE(InstructionData data) {
    std::cout << "Hello, from PRINT_MESSAGE!" << std::endl;

    data.setStringData("FUCK!");

    return GenericInstructionResponse(data);
}

InstructionID* MessageExecutor::getSharedFunctionID() {
    return _instructionId;
}