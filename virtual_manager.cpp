//
//  virtual_manager.cpp
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "virtual_manager.h"

static const int FAILED_REGISTRATION = -1;

static VManager INSTANCE;

VManager& VManager::GET_INSTANCE() {
    
    return INSTANCE;
}

InstructionID* VManager::registerSharedFunction(SharedFunction &function) {
    
    if(registerFunction(function) != FAILED_REGISTRATION) {
        return new InstructionID(function.getInternalId(), function.getStringId());
    }
    else {
        return nullptr;
    }
}

long VManager::registerFunction(SharedFunction &function) {
    
    if(function.validate()) {
        long generated_id = -1;
        
        do {
            generated_id = Utils::RANDOM_LONG(1, LONG_MAX, true);
        } while (!insertFunction(generated_id, function));
        
        return generated_id;
    }
    
    return -1;
}

bool VManager::insertFunction(long funcId, SharedFunction &function) {
    function.setInternalId(funcId);
    return vTable->insertSharedFunction(function);
}

bool VManager::findSharedFunction(long internalId, SharedFunction &returnFunc) {
    return vTable->findSharedFunction(internalId, returnFunc);
}