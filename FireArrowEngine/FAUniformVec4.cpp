//
//  FAUniformVec4.cpp
//  FireArrowEngine
//
//  Created by Simon Nilsson on 26/03/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#include "FAUniformVec4.h"

FAUniformVec4::FAUniformVec4(GLint *location, std::string name, glm::vec4 *attribute) : FAUniform(location, name) {
    this->attribute = attribute;
}

void FAUniformVec4::setUniform() {
    glUniform4f(*location, attribute->x, attribute->y, attribute->z, attribute->w);
}

std::string FAUniformVec4::toString() {
    std::stringstream ss;
    ss << "uniform vec4 " << name << ";" << std::endl;
    return ss.str();
}