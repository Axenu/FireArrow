//
//  FAPlane3D.cpp
//  FireArrowEngine
//
//  Created by Simon Nilsson on 02/02/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#include "FAPlane3D.h"

FAPlane3D::FAPlane3D() {
    this->width = 1;
    this->height = 1;
}

void FAPlane3D::setSize(float width, float height) {
    this->width = width;
    this->height = height;
}

void FAPlane3D::setShader(FAShader *shader) {
    this->shader = shader;
    glUseProgram(this->shader->shaderProgram);
    
    positionLocation = glGetAttribLocation(this->shader->shaderProgram, "in_Position");
    normalLocation = glGetAttribLocation(this->shader->shaderProgram, "in_Normal");
    
    // Get matrices uniform locations
    colorUniformLocation = glGetUniformLocation(this->shader->shaderProgram, "color");
    cameraPositionUniformLocation = glGetUniformLocation(this->shader->shaderProgram, "cameraPosition");
    projectionMatrixLocation = glGetUniformLocation(this->shader->shaderProgram,"projectionMatrix");
    viewMatrixLocation = glGetUniformLocation(this->shader->shaderProgram, "viewMatrix");
    modelMatrixLocation = glGetUniformLocation(this->shader->shaderProgram, "modelMatrix");
    
    
    
    if(positionLocation == -1) {
        std::cout << "error positionLocation" << std::endl;
    }
    if(normalLocation == -1) {
        std::cout << "error normalLocation" << std::endl;
    }
    if(colorUniformLocation == -1) {
        std::cout << "error colorUniformLocation" << std::endl;
    }
    if(cameraPositionUniformLocation == -1) {
        std::cout << "error cameraPositionUniformLocation" << std::endl;
    }
    if(projectionMatrixLocation == -1) {
        std::cout << "error projectionMatrixLocation" << std::endl;
    }
    if(viewMatrixLocation == -1) {
        std::cout << "error viewMatrixLocation" << std::endl;
    }
    if(modelMatrixLocation == -1) {
        std::cout << "error modelMatrixLocation" << std::endl;
    }
    
    //setup the model
    
    if (shader->shaderProgram == 0) {
        std::cout << "No valid shader for model" << std::endl;
        return;
    }
    
    GLfloat vertices[] = {
        width/2,0,-height/2,  0,1,0,
        -width/2,0,-height/2,  0,1,0,
        -width/2,0,height/2,   0,1,0,
        width/2,0,height/2,   0,1,0
    };
    
    GLuint indices[] = {
        0,1,2,
        0,2,3
    };
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glEnableVertexAttribArray(positionLocation);
    glEnableVertexAttribArray(normalLocation);
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) (0 * sizeof(GLfloat)));
        glEnableVertexAttribArray(normalLocation);
        glVertexAttribPointer(normalLocation, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *) (3 * sizeof(GLfloat)));
    
    this->vertices += 4;
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void FAPlane3D::setColor(glm::vec4 color) {
    this->color = color;
}

void FAPlane3D::onRender(FACamera *camera) {
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    
    glUseProgram(shader->shaderProgram);
    
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &camera->projectionMatrix[0][0]);
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &camera->viewMatrix[0][0]);
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
    glUniform4f(colorUniformLocation, color.x, color.y, color.z, color.w);
    glUniform3f(cameraPositionUniformLocation, camera->getPosition().x, camera->getPosition().y, camera->getPosition().z);
    
    glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, NULL);
    
}

void FAPlane3D::onRender(FACamera *camera, GLuint texture, std::vector<glm::mat4> &textureMatrix) {
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glUseProgram(shader->shaderProgram);
    
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &camera->projectionMatrix[0][0]);
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &camera->viewMatrix[0][0]);
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
    glUniform4f(colorUniformLocation, color.x, color.y, color.z, color.w);
    
    glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, NULL);
}

//void FAPlane3D::onRenderShadow(glm::mat4 c) {
//    
//    glBindVertexArray(myShadowVAO);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
//    
//    glUseProgram(shadowShader.shaderProgram);
//    
//    glUniformMatrix4fv(shadowModelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
//    glUniformMatrix4fv(viewProjectionMatrixLocation, 1, GL_FALSE, &c[0][0]);
//    
//    glDrawElements(GL_TRIANGLES, numberOfVertices, GL_UNSIGNED_INT, NULL);
//    
//}