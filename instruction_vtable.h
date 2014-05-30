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
#include "utils.h"

typedef InstructionResponse (*functionPtr)(InstructionData data);


typedef struct _sharedPtr {
private:
    std::string _externalId;
    long _internalId;
    
//    InstructionID instructionId;
    
    
public:
    _sharedPtr(char* strId) : _externalId(strId), _internalId(0) {}
    
    std::string& getStringId() {
        return _externalId;
    }
    
    long getInternalId() {
        return _internalId;
    }
    
    void setStringId(std::string str) {
        _externalId.erase(_externalId.begin(), _externalId.end());
        _externalId.append(str);
    }
    
    void setInternalId(long ptrId) {
        _internalId = ptrId;
    }

    bool validate() {
        // Sanity check to ensure we actually have a string id.
        Utils::TRIM_STRING(_externalId);
        if((_internalId >= 0) && (_externalId.length() > 0)) {
            return true;
        }
        return false;
    }
} SharedFunction;

class IVtable {
    /* FUNCTIONS */
private:
    
protected:
    
public:
    IVtable();
    
    ~IVtable();
    
    std::map<unsigned long, SharedFunction>::iterator findFunction(long funcId);
    
    bool insertSharedFunction(SharedFunction&);
    
    /* VARIABLES */
private:
    std::map<unsigned long, SharedFunction> vTable;
    
protected:
    
public:
    
};

#endif /* defined(__Distributor__instruction_vtable__) */
