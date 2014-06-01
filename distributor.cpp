//
//  distributor.cpp
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "distributor.h"
#include "virtual_manager.h"
#include "instruction_id.h"
#include "generic_response.h"

VManager virtualManager;

SharedFunction* sharedFunc1;
SharedFunction* sharedFunc2;
SharedFunction* sharedFunc3;

InstructionID* instruction;

GenericInstructionResponse response;

void Distributor::DISTRIBUTE() {
//    virtualManager = new VManager();

    virtualManager = Global::GET_MANAGER(EMANAGER_TYPE::VIRTUAL_MANAGER);

    sharedFunc1 = new SharedFunction("TestSharedFunction1", Distributor::MY_SHARED_FUNCTION);
    sharedFunc2 = new SharedFunction("TestSharedFunction2", Distributor::MY_SHARED_FUNCTION);
    sharedFunc3 = new SharedFunction("TestSharedFunction3", Distributor::MY_SHARED_FUNCTION);
    
    instruction = virtualManager.registerSharedFunction(*sharedFunc1);
    
    if(instruction != nullptr) {
        std::cout << "Instruction name: " << instruction->getExternalId() << std::endl;
        std::cout << "Instruction ID: " << std::to_string(instruction->getInternalId()) << std::endl;
    }

    response.initialize();
    if(instruction->executeInstruction(response)) {
        std::cout << "Instruction returned: " << response.getStringData() << std::endl;
    }
    else {
        std::cout << "Failed to execute instruction: " << instruction->getExternalId() << std::endl;
    }
    
    instruction = virtualManager.registerSharedFunction(*sharedFunc2);
    
    if(instruction != nullptr) {
        std::cout << "Instruction name: " << instruction->getExternalId() << std::endl;
        std::cout << "Instruction ID: " << std::to_string(instruction->getInternalId()) << std::endl;
    }

    response.initialize();
    if(instruction->executeInstruction(response)) {
        std::cout << "Instruction returned: " << response.getStringData() << std::endl;
    }
    else {
        std::cout << "Failed to execute instruction: " << instruction->getExternalId() << std::endl;
    }

    
    instruction = virtualManager.registerSharedFunction(*sharedFunc3);
    
    if(instruction != nullptr) {
        std::cout << "Instruction name: " << instruction->getExternalId() << std::endl;
        std::cout << "Instruction ID: " << std::to_string(instruction->getInternalId()) << std::endl;
    }

    response.initialize();
    if(instruction->executeInstruction(response)) {
        std::cout << "Instruction returned: " << response.getStringData() << std::endl;
    }
    else {
        std::cout << "Failed to execute instruction: " << instruction->getExternalId() << std::endl;
    }
}

Distributor::Distributor() {
    
}

Distributor::~Distributor() {
    
}

InstructionResponse Distributor::MY_SHARED_FUNCTION(InstructionData data) {
    std::cout << "Hello, from MY_SHARED_FUNCTION!" << std::endl;

    

    return GenericInstructionResponse(data);
}