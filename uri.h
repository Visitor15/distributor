//
//  uri.h
//  Distributor
//
//  Created by Nick C. on 5/29/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__uri__
#define __Distributor__uri__

#include <iostream>
#include <vector>

#include "global.h"
#include "network.h"
#include "shared_function.h"
#include "uri_resolver.h"

class VManager;

enum EURI_SCHEME_TYPE {
    UNKNOWN_SCHEME  = -1,
    LOCAL           = 0
};

enum EURI_PART {
    UNKNOWN_PART    = -1,
    SCHEME          =  0,
    USER_INFO       =  1,
    HOST_NAME       =  2,
    PORT            =  3,
    PATH            =  4,
    QUERY           =  5,
    FRAGMENT        =  6
};

static const int EURI_PART_COUNT = (sizeof(EURI_PART) / sizeof(int));

typedef struct uri_part_t {
    EURI_PART _part_type;
    std::string _strData;

    uri_part_t() : _part_type(EURI_PART::UNKNOWN_PART), _strData("") {}

    uri_part_t(EURI_PART partType, std::string data) : _part_type(partType), _strData(data) {}

} UriPart;

class Uri {
    /* FUNCTIONS */
private:
    void buildGenericUri();

    bool resolveInternal(SharedFunction &returnFunc);
    
protected:
    
public:
    static bool BUILD_FROM_STRING(char* buff, unsigned int length, Uri* uriPtr);

    Uri();

    Uri(long, std::string);
    
    ~Uri();
    
    void initialize();
    
    bool resolve(SharedFunction &returnFunc);

    SharedFunction& getSharedFunction();

    int getSchemeIndex();

    long getInternalId();

    std::string getExternalId();

    std::string getScheme();

    std::string getUriPath();
    
    /* VARIABLES */
private:
    long _internalId;

    std::string _externalId;

    SharedFunction* _internalSharedFunc;

    std::vector<UriPart> _uriParts;
    
protected:
    
public:

};

#endif /* defined(__Distributor__uri__) */
