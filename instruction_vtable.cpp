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

void IVtable::executeFunction(long funcId) {

}