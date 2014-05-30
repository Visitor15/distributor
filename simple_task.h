//
//  simple_task.h
//  Distributor
//
//  Created by Nick C. on 3/21/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef Distributor_simple_task_h
#define Distributor_simple_task_h

#include "task.h"

class SimpleTask : public Task {
    
public:
    SimpleTask();
    
    ~SimpleTask();
    
    virtual void do_Task() = 0;
    
    virtual void pause_Task() = 0;
    
    virtual void resume_Task() = 0;
    
    virtual void stop_Task() = 0;
};

#endif
