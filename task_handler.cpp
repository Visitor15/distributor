//
//  task_handler.cpp
//  Distributor
//
//  Created by Nick C. on 3/21/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "task_handler.h"

TaskHandler::TaskHandler() {
    
}

TaskHandler::~TaskHandler() {
    
}

bool TaskHandler::registerTask(long jobId, FunctionPointer func) {
    
    if(handlerMap.find(jobId) == handlerMap.end()) {
        //handlerMap.insert(std::make_pair(jobId, std::vector<long, std::vector<FunctionPointer>>()));
    }
    
    return false;
}

void TaskHandler::purgeBadFunctionPointers() {
    
}