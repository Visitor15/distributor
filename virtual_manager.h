//
//  virtual_manager.h
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__virtual_manager__
#define __Distributor__virtual_manager__

#include <iostream>

#include "instruction_vtable.h"
#include "instruction_id.h"
#include "manager.h"

class InstructionID;

class VManager : public Manager {
    /* FUNCTIONS */
private:
    VManager(VManager const&);          // Do not implement. This is a SINGLETON!
    void operator=(VManager const&);    // Do not implement. This is a SINGLETON!

    long registerFunction(SharedFunction &func);
    
    bool insertFunction(long funcId, SharedFunction &function);
    
protected:
    
public:
    static VManager& GET_INSTANCE();
    
    VManager() { vTable = new IVtable(); }
    
    ~VManager() {
        if(vTable != nullptr) {
            delete vTable;
            vTable = nullptr;
        }
    }

    InstructionID* registerSharedFunction(SharedFunction& func);

    bool findSharedFunction(long internalId, SharedFunction &returnFunc);

    bool replaceFunction(long funcId, SharedFunction &function);
    
//    InstructionID* registerInstruction(functionPtr);
    
    /* VARIABLES */
private:
    IVtable* vTable;
    
protected:
    
public:
    
};

#endif /* defined(__Distributor__virtual_manager__) */
