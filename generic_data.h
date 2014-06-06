//
//  generic_data.h
//  Distributor
//
//  Created by Nick C. on 5/31/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef Distributor_generic_data_h
#define Distributor_generic_data_h

#include "serializable.h"

template <class T> class GenericData : public Serializable<T> {
    /* FUNCTIONS */
private:

protected:
    char* getData();

public:
    GenericData() {};
    virtual ~GenericData() {};

    virtual void serialize(std::ostream &stream) = 0;

    virtual void deSerialize(std::ostream &stream) = 0;

    /* VARIABLES */
private:

protected:
    std::string _strData;
    
public:
    
    
};

#endif
