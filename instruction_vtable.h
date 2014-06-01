//
//  instruction_vtable.h
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__instruction_vtable__
#define __Distributor__instruction_vtable__

#include <iostream>
#include <map>

#include "instruction_id.h"
#include "instruction_data.h"
#include "instruction_response.h"
#include "shared_function.h"
#include "utils.h"

/*
 *      CLASS
 */
class IVtable {
    /* FUNCTIONS */
private:
    
protected:
    
public:
    IVtable();
    
    ~IVtable();
    
    void executeFunction(long funcId);
    
    bool insertSharedFunction(SharedFunction&);

    bool findSharedFunction(long internalId, SharedFunction& foundFunc);
    
    /* VARIABLES */
private:
    std::map<unsigned long, SharedFunction> vTable;
    
protected:
    
public:
    
};

#endif /* defined(__Distributor__instruction_vtable__) */
