#include "FALine.h"

FALine::FALine() {
	this->setName("FALine");
	this->setColor(glm::vec4(0.5, 0.5, 0.5, 1));
	this->setScale(1);
}

void FALine::setShader(FAShader *shader) {

	this->shader = shader;
	glUseProgram(shader->shaderProgram);

	positionLocation = glGetAttribLocation(shader->shaderProgram, "in_Position");

	// Get matrices uniform locations
	colorUniformLocation = glGetUniformLocation(shader->shaderProgram, "color");
	projectionMatrixLocation = glGetUniformLocation(shader->shaderProgram, "projectionMatrix");
	viewMatrixLocation = glGetUniformLocation(shader->shaderProgram, "viewMatrix");
	modelMatrixLocation = glGetUniformLocation(shader->shaderProgram, "modelMatrix");



	if (positionLocation == -1) {
		std::cout << "error positionLocation" << std::endl;
	}
	if (colorUniformLocation == -1) {
		std::cout << "error colorUniformLocation" << std::endl;
	}
	if (projectionMatrixLocation == -1) {
		std::cout << "error projectionMatrixLocation" << std::endl;
	}
	if (viewMatrixLocation == -1) {
		std::cout << "error viewMatrixLocation" << std::endl;
	}
	if (modelMatrixLocation == -1) {
		std::cout << "error modelMatrixLocation" << std::endl;
	}
}

void FALine::setColor(glm::vec4 c) {
	color = c;
}

void FALine::setPoints(glm::vec3 *v1, glm::vec3 *v2) {

	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);

	if (shader->shaderProgram == 0) {
		std::cout << "No valid shader for model" << std::endl;
		return;
	}

	GLfloat vertices[6];
	vertices[0] = (*v1).x;
	vertices[1] = (*v1).y;
	vertices[2] = (*v1).z;
	vertices[3] = (*v2).x;
	vertices[4] = (*v2).y;
	vertices[5] = (*v2).z;

	GLushort indices[2] = {
		0,1
	};

	numberOfVertices = 2;

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), &vertices[0], GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 2 * sizeof(GLushort), &indices[0], GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glEnableVertexAttribArray(positionLocation);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void FALine::onRender(FACamera *camera) {

	glBindVertexArray(VAO);
	glEnableVertexAttribArray(positionLocation);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glUseProgram(shader->shaderProgram);

	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &camera->projectionMatrix[0][0]);
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &camera->viewMatrix[0][0]);
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
	glUniform4f(colorUniformLocation, color.x, color.y, color.z, color.w);

	glDrawElements(GL_LINES, numberOfVertices, GL_UNSIGNED_SHORT, NULL);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(positionLocation);
	glBindVertexArray(0);

	glUseProgram(0);

}

void FALine::onRender(FACamera *camera, GLuint texture, glm::mat4 *textureMatrix) {
	glDisable(GL_CULL_FACE);
	glBindVertexArray(VAO);
	glEnableVertexAttribArray(positionLocation);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glUseProgram(shader->shaderProgram);

	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &camera->projectionMatrix[0][0]);
	glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &camera->viewMatrix[0][0]);
	glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
	glUniform4f(colorUniformLocation, color.x, color.y, color.z, color.w);

	glDrawElements(GL_LINES, numberOfVertices, GL_UNSIGNED_SHORT, NULL);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(positionLocation);
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);

	glUseProgram(0);
	glEnable(GL_CULL_FACE);
}

void FALine::onUpdate(double dt, glm::mat4 *m) {

}


FALine::~FALine() {
	//dealloc
}