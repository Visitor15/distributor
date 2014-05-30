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
#include "instruction_response.h"

VManager* virtualManager;

SharedFunction* sharedFunc1;
SharedFunction* sharedFunc2;
SharedFunction* sharedFunc3;

InstructionID* instruction;

void Distributor::DISTRIBUTE() {
    virtualManager = new VManager();
    
    sharedFunc1 = new SharedFunction("TestSharedFunction1");
    sharedFunc2 = new SharedFunction("TestSharedFunction2");
    sharedFunc3 = new SharedFunction("TestSharedFunction3");
    
    instruction = virtualManager->registerSharedFunction(*sharedFunc1);
    
    if(instruction != nullptr) {
        std::cout << "Instruction ID: " << std::to_string(instruction->getInternalId()) << std::endl;
        InstructionResponse response;
        if(instruction->fetchInstruction(response)) {
            std::cout << "Instruction response: " << response.getStringData() << std::endl;
        }
    }
    
    instruction = virtualManager->registerSharedFunction(*sharedFunc2);
    
    if(instruction != nullptr) {
        std::cout << "Instruction ID: " << std::to_string(instruction->getInternalId()) << std::endl;
    }
    
    instruction = virtualManager->registerSharedFunction(*sharedFunc3);
    
    if(instruction != nullptr) {
        std::cout << "Instruction ID: " << std::to_string(instruction->getInternalId()) << std::endl;
    }
    
    
}

Distributor::Distributor() {
    
}

Distributor::~Distributor() {
    
}