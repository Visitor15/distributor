//
//  instruction_vtable.cpp
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "instruction_vtable.h"

IVtable::IVtable() {
    
}

IVtable::~IVtable() {
    
}

bool IVtable::insertSharedFunction(SharedFunction &func) {
    if(vTable.find(func.getInternalId()) != vTable.end()) {
        return false;
    }
    
    vTable.insert(std::make_pair(func.getInternalId(), func));
    
    return true;
}

bool IVtable::replaceSharedFunction(SharedFunction &func) {
    std::map<unsigned long, SharedFunction>::iterator itter;
    itter = vTable.find(func.getInternalId());
    if(itter != vTable.end()) {
        (*itter).second = func;
        return true;
    }

    return false;
}

void IVtable::executeFunction(long funcId) {

}

bool IVtable::findSharedFunction(long internalId, SharedFunction &returnFunc) {
    std::map<unsigned long, SharedFunction>::iterator itter;

    itter = vTable.find(internalId);
    if(itter != vTable.end()) {
        returnFunc = itter->second;
        return true;
    }

    return false;
}