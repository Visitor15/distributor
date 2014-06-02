//
//  message_executor.h
//  Distributor
//
//  Created by Nick C. on 6/1/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__message_executor__
#define __Distributor__message_executor__

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <sstream>
#endif

#include <iostream>

#include "virtual_manager.h"
#include "shared_function.h"
#include "generic_response.h"
#include "instruction_id.h"

class MessageExecutor {
    /* FUNCTIONS */
private:
    static InstructionResponse PRINT_MESSAGE(InstructionData data);

    static InstructionResponse DO_CALCULATION(InstructionData data);

protected:

public:
    MessageExecutor();

    ~MessageExecutor();

    void initialize();

    InstructionID* getSharedFunctionID();

    /* Only for testing purposes. */
    void changeVtableEntry();

    /* VARIABLES */
private:
    InstructionID* _instructionId;

protected:
    
public:
    
};

#endif /* defined(__Distributor__message_executor__) */
