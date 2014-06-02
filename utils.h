//
//  utils.h
//  Distributor
//
//  Created by Nick C. on 5/29/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef __Distributor__utils__
#define __Distributor__utils__

#include <iostream>
#include <time.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <algorithm>
#include <functional>
#include <cctype>
#endif

class Utils {
    /* FUNCTIONS */
private:
    
protected:
    
public:
    Utils() { srand(time(NULL)); }
    
    ~Utils() {}
    
    static inline void TRIM_STRING(std::string &str) {
        Utils::trim(str);
    }
    
    // trim from start
    static inline std::string& ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
    }
    
    // trim from end
    static inline std::string& rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
    }
    
    // trim from both ends
    static inline std::string& trim(std::string &s) {
        return ltrim(rtrim(s));
    }
    
    static inline long RANDOM_LONG(long min, long max, bool inclusive) {
        srand(time(NULL));
        return (inclusive) ? (min + (rand() % max)) : (min + (rand() % (max - 1)));
    }
    
    /* VARIABLES */
private:
    
protected:
    
public:
};

#endif /* defined(__Distributor__utils__) */
