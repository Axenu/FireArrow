//
//  FAMaterial.h
//  FireArrowEngine
//
//  Created by Simon Nilsson on 25/03/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#ifndef __FireArrowEngine__FAMaterial__
#define __FireArrowEngine__FAMaterial__

#include <stdio.h>
#include <sstream>
#include <glm/glm.hpp>
#include <vector>
#include "FAShader.h"
#include "FAUniform.h"
#include "FAUniformVec4.h"

using namespace std;

class FAMaterial {
    
private:
    
    FAShader *shadowShader;
    FAShader *shader;
//    FAShader *shader;
    
    std::vector<FAUniform *> uniforms;
    
    glm::vec4 color;
    
    int version;
    
    GLint texture;
    bool hasShadow;
    bool hasVertexNormal;
    bool hasVertexColor;
    bool hasVertexUV;
    
    bool hasColor;
    bool hasTexture;
    bool hasPointLight;
    
    bool hasGlobalLight;
    
    GLint positionAttributeLocation;
    GLint normalAttributeLocation;
    GLint colorAttributeLocation;
    GLint uvAttributeLocation;
    
    GLint colorUniformLocation;
    GLint textureUniformLocation;
    
public:
    FAMaterial();
    void init();
    void setTexture(GLint texrure);
    void setColor(glm::vec4 color);
    
    void setGlobalLight();
    
    ~FAMaterial();
    
};

#endif /* defined(__FireArrowEngine__FAMaterial__) */
