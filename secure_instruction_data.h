//
//  secure_instruction_data.h
//  Distributor
//
//  Created by Nick C. on 5/31/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#ifndef Distributor_secure_instruction_data_h
#define Distributor_secure_instruction_data_h

class SecureInstructionData : GenericData<SecureInstructionData> {
    /* FUNCTIONS */
private:
    char* getDataSecure();

protected:

public:
    SecureInstructionData();

    ~SecureInstructionData();

    void serialize(std::ostream &stream);

    void deSerialize(std::ostream &stream);

    bool doAuthentication();

    char* getData() {
        if(doAuthentication()) {
            return getDataSecure();
        }
        else {
            return NULL;
        }
    }

    /* VARIABLES */
private:

protected:

public:
    
};

#endif
