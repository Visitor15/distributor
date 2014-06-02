//
//  shared_function.h
//  Distributor
//
//  Created by Nick C. on 6/1/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef Distributor_shared_function_h
#define Distributor_shared_function_h

#include "instruction_response.h"
#include "instruction_data.h"
#include "utils.h"

typedef InstructionResponse (*functionPtr)(InstructionData data);

typedef struct _sharedPtr {
private:
    std::string _externalId;
    long _internalId;

    functionPtr _funcPtr;


public:
    _sharedPtr() : _externalId(""), _internalId(-1) {}

    _sharedPtr(char* strId) : _externalId(strId), _internalId(0) {}

    _sharedPtr(char* strId, functionPtr ptr) : _externalId(strId), _internalId(0), _funcPtr(ptr) {}

    ~_sharedPtr() {}

    std::string getStringId() {
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

    InstructionResponse executeFunction(InstructionData &functionData) {
        return (*_funcPtr)(functionData);
    }

} SharedFunction;

#endif
