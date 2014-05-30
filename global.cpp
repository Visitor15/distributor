//
//  global.cpp
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "global.h"

static Global SINGLETON;

Global::Global() {
    
}

Global::~Global() {
    
}

Manager& Global::GET_MANAGER(EMANAGER_TYPE managerType) {
    return SINGLETON.getManager(managerType);
}

Manager& Global::getManager(EMANAGER_TYPE managerType) {
    std::map<int, Manager>::iterator it = registeredManagers.begin();
    
    if(it == registeredManagers.end()) {
        //TODO: Throw exception.
    }
    
    return it->second;
}