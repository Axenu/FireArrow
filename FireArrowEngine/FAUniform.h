//
//  FAUniform.h
//  FireArrowEngine
//
//  Created by Simon Nilsson on 26/03/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#ifndef __FireArrowEngine__FAUniform__
#define __FireArrowEngine__FAUniform__

#define GLFW_INCLUDE_GLCOREARB

#include <stdio.h>
#include <sstream>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class FAUniform {
    
private:
    
public:
    FAUniform();
    FAUniform(GLint *location, std::string name);
    
    virtual void setUniform() = 0;
    virtual std::string toString() = 0;
    
    ~FAUniform();
    
protected:
    GLint *location;
    std::string name;
};


#endif /* defined(__FireArrowEngine__FAUniform__) */
