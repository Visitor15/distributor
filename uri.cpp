//
//  uri.cpp
//  Distributor
//
//  Created by Nick C. on 5/29/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <sstream>
#endif

#include "uri.h"
#include "virtual_manager.h"

Uri::Uri() {
    initialize();
}

Uri::Uri(long internalId, std::string externalId) {
    _internalId = internalId;
    _externalId = externalId;

    initialize();
}

Uri::~Uri() {

}

void Uri::initialize() {
    buildGenericUri();
}

bool Uri::resolve(SharedFunction &returnFunc) {
    return resolveInternal(returnFunc);
}

void Uri::buildGenericUri() {
    for(int i = 0; i < EURI_PART_COUNT; ++i) {
        switch(i) {
            case EURI_PART::SCHEME: {
                _uriParts.push_back(UriPart(EURI_PART::SCHEME, SCHEMES::LOCAL()));
                break;
            }
            case EURI_PART::USER_INFO: {
                _uriParts.push_back(UriPart(EURI_PART::USER_INFO, SCHEMES::LOCAL()));
                break;
            }
            case EURI_PART::HOST_NAME: {
                _uriParts.push_back(UriPart(EURI_PART::HOST_NAME, SCHEMES::LOCAL()));
                break;
            }
            case EURI_PART::PORT: {
                _uriParts.push_back(UriPart(EURI_PART::PORT, std::to_string(DEFAULT_LISTEN_PORT)));
                break;
            }
            case EURI_PART::PATH: {
                _uriParts.push_back(UriPart(EURI_PART::PATH, ""));
                break;
            }
            case EURI_PART::QUERY: {
                _uriParts.push_back(UriPart(EURI_PART::QUERY, ""));
                break;
            }
            case EURI_PART::FRAGMENT: {
                _uriParts.push_back(UriPart(EURI_PART::FRAGMENT, ""));
                break;
            }
        }
    }
}

bool Uri::resolveInternal(SharedFunction &returnFunc) {
    if(_uriParts.at(EURI_PART::SCHEME)._strData.compare(SCHEMES::LOCAL()) == 0) {
        VManager::GET_INSTANCE().findSharedFunction(_internalId, returnFunc);
        return true;
    }
    return false;
}