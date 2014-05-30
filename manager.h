//
//  manager.h
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef Distributor_manager_h
#define Distributor_manager_h

class Manager {
    /* FUNCTIONS */
private:
    
protected:
    
    
public:
    static Manager& EMPTY_MANAGER() {
        static Manager INSTANCE;
        
        return INSTANCE;
    }
    
    static Manager& GET_INSTANCE();
    
    Manager() {};
    
    ~Manager() {};
    
    /* VARIABLES */
private:
    
protected:
    
public:
    
};

#endif
