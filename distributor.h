//
//  distributor.h
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__distributor__
#define __Distributor__distributor__

#include <iostream>

#include "instruction_response.h"

class Distributor {
    /* FUNCTIONS */
private:
    static InstructionResponse MY_SHARED_FUNCTION(InstructionData data);

    static InstructionResponse MY_SHARED_FUNCTION2(InstructionData data);

    static InstructionResponse MY_SHARED_FUNCTION3(InstructionData data);
    
protected:
    
public:
    static void DISTRIBUTE();
    
    Distributor();
    
    ~Distributor();
    
    /* VARIABLES */
private:
    
protected:
    
public:
    
};

#endif /* defined(__Distributor__distributor__) */
