//
//  distributor.cpp
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "distributor.h"
#include "global.h"
#include "virtual_manager.h"
#include "instruction_id.h"
#include "generic_response.h"



SharedFunction* sharedFunc1;
SharedFunction* sharedFunc2;
SharedFunction* sharedFunc3;

VManager virtualManager;
InstructionID* instruction;

GenericInstructionResponse* response;
InstructionData* data;

void Distributor::DISTRIBUTE() {
//    virtualManager = new VManager();

//    virtualManager = std::dynamic_cast<VManager*>(Global::GET_MANAGER(EMANAGER_TYPE::VIRTUAL_MANAGER));

    virtualManager = VManager::GET_INSTANCE();

    sharedFunc1 = new SharedFunction("TestSharedFunction1", Distributor::MY_SHARED_FUNCTION3);
    sharedFunc2 = new SharedFunction("TestSharedFunction2", Distributor::MY_SHARED_FUNCTION);
    sharedFunc3 = new SharedFunction("TestSharedFunction3", Distributor::MY_SHARED_FUNCTION2);
    
    instruction = virtualManager.registerSharedFunction(*sharedFunc1);
    
    if(instruction != nullptr) {
        std::cout << "Instruction name: " << instruction->getExternalId() << std::endl;
        std::cout << "Instruction ID: " << std::to_string(instruction->getInternalId()) << std::endl;
    }

    response = new GenericInstructionResponse();
    response->initialize();
    data = new InstructionData();
    if(instruction->executeInstruction(*response, *data)) {
        std::cout << "Instruction returned: " << response->getStringData() << std::endl;
    }
    else {
        std::cout << "Failed to execute instruction: " << instruction->getExternalId() << std::endl;
    }
    
    instruction = virtualManager.registerSharedFunction(*sharedFunc2);
    
    if(instruction != nullptr) {
        std::cout << "Instruction name: " << instruction->getExternalId() << std::endl;
        std::cout << "Instruction ID: " << std::to_string(instruction->getInternalId()) << std::endl;
    }

    response = new GenericInstructionResponse();
    response->initialize();
    data = new InstructionData();
    if(instruction->executeInstruction(*response, *data)) {
        std::cout << "Instruction returned: " << response->getStringData() << std::endl;
    }
    else {
        std::cout << "Failed to execute instruction: " << instruction->getExternalId() << std::endl;
    }

    
    instruction = virtualManager.registerSharedFunction(*sharedFunc3);
    
    if(instruction != nullptr) {
        std::cout << "Instruction name: " << instruction->getExternalId() << std::endl;
        std::cout << "Instruction ID: " << std::to_string(instruction->getInternalId()) << std::endl;
    }

    response = new GenericInstructionResponse();
    response->initialize();
    data = new InstructionData();
    if(instruction->executeInstruction(*response, *data)) {
        std::cout << "Instruction returned: " << response->getStringData() << std::endl;
    }
    else {
        std::cout << "Failed to execute instruction: " << instruction->getExternalId() << std::endl;
    }
}

Distributor::Distributor() {
    
}

Distributor::~Distributor() {
    if(data) {
        delete data;
        data = nullptr;
    }

    if(response) {
        delete response;
        response = nullptr;
    }

    if(instruction) {
        delete instruction;
        instruction = nullptr;
    }

    if(sharedFunc1) {
        delete sharedFunc1;
        sharedFunc1 = nullptr;
    }

    if(sharedFunc2) {
        delete sharedFunc2;
        sharedFunc2 = nullptr;
    }

    if(sharedFunc3) {
        delete sharedFunc3;
        sharedFunc3 = nullptr;
    }
}

InstructionResponse Distributor::MY_SHARED_FUNCTION(InstructionData data) {
    std::cout << "Hello, from MY_SHARED_FUNCTION!" << std::endl;

    return GenericInstructionResponse(data);
}

InstructionResponse Distributor::MY_SHARED_FUNCTION2(InstructionData data) {
    std::cout << "Hello, from MY_SHARED_FUNCTION2!" << std::endl;

    return GenericInstructionResponse(data);
}

InstructionResponse Distributor::MY_SHARED_FUNCTION3(InstructionData data) {
    std::cout << "Hello, from MY_SHARED_FUNCTION3!" << std::endl;

    return GenericInstructionResponse(data);
}