//
//  distributor.cpp
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <sstream>
#endif

#include "distributor.h"
#include "global.h"
#include "virtual_manager.h"
#include "instruction_id.h"
#include "generic_response.h"
#include "message_executor.h"
#include "network.h"

SharedFunction* sharedFunc1;
SharedFunction* sharedFunc2;
SharedFunction* sharedFunc3;

MessageExecutor* messageExec;

InstructionID* instruction;

GenericInstructionResponse* response;
InstructionData* data;

TCPSocket* serverSocket;
TCPSocket* clientSocket;

void Distributor::DISTRIBUTE() {

    serverSocket = new TCPSocket();
    serverSocket->setPort(DEFAULT_LISTEN_PORT);
    serverSocket->connectTo();
    serverSocket->setSocketListening(DEFAULT_LISTEN_PORT);

//    clientSocket = new TCPSocket("127.0.0.1", DEFAULT_LISTEN_PORT);

    messageExec = new MessageExecutor();

    sharedFunc1 = new SharedFunction("TestSharedFunction1", Distributor::MY_SHARED_FUNCTION3);
    sharedFunc2 = new SharedFunction("TestSharedFunction2", Distributor::MY_SHARED_FUNCTION);
    sharedFunc3 = new SharedFunction("TestSharedFunction3", Distributor::MY_SHARED_FUNCTION2);
    
    instruction = VManager::GET_INSTANCE().registerSharedFunction(*sharedFunc1);
    
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
    
    instruction = VManager::GET_INSTANCE().registerSharedFunction(*sharedFunc2);
    
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

    /* Message executor */
    instruction = messageExec->getSharedFunctionID();
    response = new GenericInstructionResponse();
    response->initialize();
    data = new InstructionData();
    if(instruction->executeInstruction(*response, *data)) {
        std::cout << "Instruction returned: " << response->getStringData() << std::endl;
    }
    else {
        std::cout << "Failed to execute instruction: " << instruction->getExternalId() << std::endl;
    }
    
    instruction = VManager::GET_INSTANCE().registerSharedFunction(*sharedFunc3);
    
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

    messageExec->changeVtableEntry();
    /* Message executor */
    instruction = messageExec->getSharedFunctionID();
    response = new GenericInstructionResponse();
    response->initialize();
    data = new InstructionData();
    if(instruction->executeInstruction(*response, *data)) {
        std::cout << "Instruction returned: " << response->getStringData() << std::endl;
    }
    else {
        std::cout << "Failed to execute instruction: " << instruction->getExternalId() << std::endl;
    }

    std::cout << "Programming terminating" << std::endl;

    int _val;
    std::cin >> _val;
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
    data.setStringData("Hello, from MY_SHARED_FUNCTION!");
    return GenericInstructionResponse(data);
}

InstructionResponse Distributor::MY_SHARED_FUNCTION2(InstructionData data) {
    data.setStringData("Hello, from MY_SHARED_FUNCTION2!");
    return GenericInstructionResponse(data);
}

InstructionResponse Distributor::MY_SHARED_FUNCTION3(InstructionData data) {
    data.setStringData("Hello, from MY_SHARED_FUNCTION3!");
    return GenericInstructionResponse(data);
}