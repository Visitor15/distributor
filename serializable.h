//
//  serializable.h
//  Distributor
//
//  Created by Nick C. on 5/31/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef Distributor_serializable_h
#define Distributor_serializable_h

#include <iostream>

template <class T> class Serializable {
    /* FUNCTIONS */
private:

protected:

public:
    Serializable() {};

    virtual ~Serializable() {};

    virtual void serialize(std::ostream &stream) = 0;

    virtual void deSerialize(std::ostream &stream) = 0;

    /* VARIABLES */
private:

protected:


public:
    
    
};

#endif
