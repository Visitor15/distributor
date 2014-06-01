//
//  global.h
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef Distributor_global_h
#define Distributor_global_h

#include <atomic>
#include <map>
#include <vector>
#include <iostream>

class SCHEMES {
public:
    inline static std::string LOCAL() {
        return "local";
    }

    inline static std::string LOCAL_NETWORK() {
        return "local_net";
    }

    inline static std::string INTERNET() {
        return "net";
    }
};

enum EMANAGER_TYPE {
    TASK_MANAGER = 0,
    VIRTUAL_MANAGER = 1
};

class Global {
    /* FUNCTIONS */
private:
    Global(Global const&);
    void operator=(Global const&);
    
//    Manager& getManager(EMANAGER_TYPE managerType);

protected:
    
public:
//    static Manager& GET_MANAGER(EMANAGER_TYPE managerType);

    Global();
    
    ~Global();
    
    /* VARIABLES */
private:
//    std::map<int, Manager> registeredManagers;

protected:
    
public:
    
};

#endif
