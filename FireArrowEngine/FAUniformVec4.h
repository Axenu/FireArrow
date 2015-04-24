//
//  FAUniformVec4.h
//  FireArrowEngine
//
//  Created by Simon Nilsson on 26/03/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#ifndef __FireArrowEngine__FAUniformVec4__
#define __FireArrowEngine__FAUniformVec4__

#include "FAUniform.h"

class FAUniformVec4 : public FAUniform {
    
private:
    glm::vec4 *attribute;
    
public:
    FAUniformVec4();
    FAUniformVec4(GLint *location, std::string name, glm::vec4 *attribute);
    
    void setUniform();
    
    std::string toString();
    
    ~FAUniformVec4();
};

#endif /* defined(__FireArrowEngine__FAUniformVec4__) */
