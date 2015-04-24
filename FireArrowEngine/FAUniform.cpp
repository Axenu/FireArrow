//
//  FAUniform.cpp
//  FireArrowEngine
//
//  Created by Simon Nilsson on 26/03/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#include "FAUniform.h"


FAUniform::FAUniform(GLint *location, std::string name) {
    this->location = location;
    this->name = name;
}