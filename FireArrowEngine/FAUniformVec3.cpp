//
//  FAUniformVec3.cpp
//  FireArrowEngine
//
//  Created by Simon Nilsson on 26/03/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#include "FAUniformVec3.h"

FAUniformVec3::FAUniformVec3(GLint *location, std::string name, glm::vec3 *attribute) : FAUniform(location, name) {
    this->attribute = attribute;
}

void FAUniformVec3::setUniform() {
    glUniform3f(*location, attribute->x, attribute->y, attribute->z);
}

std::string FAUniformVec3::toString() {
    std::stringstream ss;
    ss << "uniform vec3 " << name << ";" << std::endl;
    return ss.str();
}