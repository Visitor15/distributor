//
//  task_handler.h
//  Distributor
//
//  Created by Nick C. on 3/21/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef Distributor_task_handler_h
#define Distributor_task_handler_h

#include <map>
#include <vector>

#include "task_payload.h"

/* Function pointer: void Function(TaskPayLoad data) */
typedef void (*FunctionPointer)(TaskPayload);

class TaskHandler {
public:
    TaskHandler();
    
    ~TaskHandler();
    
    void purgeBadFunctionPointers();
    
    bool registerTask(long jobId, FunctionPointer func);
    
private:
    std::map<long, std::vector<FunctionPointer>> handlerMap;
};

#endif
