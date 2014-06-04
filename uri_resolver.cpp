//
//  uri_resolver.cpp
//  Distributor
//
//  Created by Nick C. on 5/30/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "uri_resolver.h"
#include "uri.h";
#include "virtual_manager.h"

UriResolver::UriResolver() {

}

UriResolver::UriResolver(Uri* uriPtr) {
    _internalUriPtr = uriPtr;
}

UriResolver::~UriResolver() {
    if(_internalUriPtr) {
        delete _internalUriPtr;
        _internalUriPtr = nullptr;
    }
}

bool UriResolver::resolve(char* buff, unsigned int length) {
    if(_internalUriPtr == nullptr) {
        /* We don't have a URI to resolver - return false. */
        return false;
    }
    else if((buff != nullptr) && (strlen(buff) > 0)) {
        if(_internalUriPtr == nullptr) {
            if(!Uri::BUILD_FROM_STRING(buff, length, _internalUriPtr)) {
                /* If we CANNOT build the URI - return false. */
                return false;
            }
        }
    }
    else {
        // We should have a _internalUriPtr
    }
    return resolveUriInternal();
}

bool UriResolver::resolveUriInternal() {
    /* Sanity check to ensure we actually a Uri. */
    if(_internalUriPtr == nullptr) {
        return false;
    }
    /* Depending on the scheme, URIs can be handled differently. */
    int _scheme = _internalUriPtr->getSchemeIndex();
    if(_scheme > -1) {
        switch(_internalUriPtr->getSchemeIndex()) {
            case ESCHEME::ELOCAL:
                VManager::GET_INSTANCE().findSharedFunction(_internalUriPtr->getInternalId(), _internalUriPtr->getSharedFunction());
                break;
            case ESCHEME::EHTTP:
                break;
            case ESCHEME::EHTTPS:
                break;
            case ESCHEME::EFTP:
                break;
            case ESCHEME::EDIRECT_CONNECT:
                break;
            default:
                // ERROR
                break;
        }

        return true;
    }
    
    return false;
}