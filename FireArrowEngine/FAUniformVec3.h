//
//  FAUniformVec3.h
//  FireArrowEngine
//
//  Created by Simon Nilsson on 26/03/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#ifndef __FireArrowEngine__FAUniformVec3__
#define __FireArrowEngine__FAUniformVec3__

#include "FAUniform.h"

class FAUniformVec3 : public FAUniform {
    
private:
    glm::vec3 *attribute;
    
public:
    FAUniformVec3();
    FAUniformVec3(GLint *location, std::string name, glm::vec3 *attribute);
    
    void setUniform();
    
    std::string toString();
    
    ~FAUniformVec3();
};


#endif /* defined(__FireArrowEngine__FAUniformVec3__) */
