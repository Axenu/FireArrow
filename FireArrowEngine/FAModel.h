//
//  FAModel.h
//  FireArrow
//
//  Created by Simon Nilsson on 16/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FAModel__
#define __FireArrow__FAModel__

#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "FAShader.h"
#include "FANode.h"

class FAModel : public FANode {
private:
    GLuint myVBO;
    GLuint myEBO;
    GLuint myVAO;
	GLuint myShadowVBO;
	GLuint myShadowVAO;
    GLint positionLocation;
    GLint normalLocation;
    GLint colorLocation;
    GLint colorUniformLoc;
	GLint positionLocShadow;
    glm::vec4 color;
	FAShader shadowShader;
    GLuint numberOfVertices;
    GLint projectionMatrixLocation;
    GLint viewMatrixLocation;
    GLint modelMatrixLocation;
    GLint normalMatrix;
	GLint viewProjectionMatrixLocation;
    GLint shadowModelMatrixLocation;
	GLint textureMatrixLocation;
	GLint shadowMapLocation;
    
    bool positionAttribute = false;
    bool normalAttribute = false;
    bool colorAttribute = false;
    
    GLint attributes = 0;
	
	std::vector<float> getVerticeArray(std::ifstream file, int numberOfVertices);
	
public:
    
    FAModel();
    ~FAModel();
    void setShader(FAShader *shader);
    void setModel(std::vector<GLfloat> vertices, std::vector<GLuint> indices);
    void setModel(std::string path);
	void setFAModel(std::string path);
	void setXModel(std::string path);
    void setColor(glm::vec4 c);
    void setPositionAttribute(bool b);
    void setNormalAttribute(bool b);
    void setColorAttribute(bool b);
    
protected:
	virtual void onRender(FACamera *camera);
	virtual void onRender(FACamera *camera, GLuint texture, std::vector<glm::mat4> &textureMatrix);
    virtual void onRenderShadow(glm::mat4 c);
	virtual void onUpdate(float dt);
	
};

#endif /* defined(__FireArrow__FAModel__) */
