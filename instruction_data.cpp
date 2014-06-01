//
//  instruction_data.cpp
//  Distributor
//
//  Created by Nick C. on 5/28/14.
//  Copyright (c) 2014 fORGED. All rights reserved.
//

#include "instruction_data.h"


InstructionData::InstructionData() {

}

InstructionData::~InstructionData() {

}

void InstructionData::setStringData(char* data) {
    _strData = "";
    _strData.append(data);
}

std::string InstructionData::getStringData() {
    return _strData;
}

void InstructionData::serialize(std::ostream &stream) {

}

void InstructionData::deSerialize(std::ostream &stream) {

}