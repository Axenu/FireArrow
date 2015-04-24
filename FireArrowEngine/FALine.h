//
//  FAWireLine.h
//  FireArrow
//
//  Created by Simon Nilsson on 08/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__FALine__
#define __FireArrow__FALine__
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "FANode.h"

class FALine : public FANode {

private:
	GLuint positionLocation;
	GLuint colorUniformLocation;
	GLuint projectionMatrixLocation;
	GLuint viewMatrixLocation;
	GLuint modelMatrixLocation;

	GLuint VBO;
	GLuint EBO;
	GLuint VAO;

	glm::vec4 color;
	GLuint numberOfVertices;

public:
	FALine();
	~FALine();
	void setShader(FAShader *shader);
	void setPoints(glm::vec3 *v1, glm::vec3 *v2);
	void setColor(glm::vec4 c);

protected:
	virtual void onRender(FACamera *camera);
	virtual void onRender(FACamera *camera, GLuint texture, glm::mat4 *textureMatrix);
	virtual void onUpdate(double dt, glm::mat4 *m);
};

#endif /* defined(__FireArrow__FAWireFrame__) */
