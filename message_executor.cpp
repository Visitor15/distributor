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

InstructionResponse MessageExecutor::DO_CALCULATION(InstructionData data) {
    std::cout << "Hello, from DO_CALCULATION!" << std::endl;

    int returnVal = 138 + 138;
    data.setStringData((char*) std::to_string(returnVal).c_str());

    return GenericInstructionResponse(data);
}

InstructionID* MessageExecutor::getSharedFunctionID() {
    return _instructionId;
}

void MessageExecutor::changeVtableEntry() {
    VManager::GET_INSTANCE().replaceFunction(mySharedFunc->getInternalId(), SharedFunction("ReplacedSharedFunction", MessageExecutor::DO_CALCULATION));
}