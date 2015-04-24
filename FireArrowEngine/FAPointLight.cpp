//
//  FAPointLight.cpp
//  FireArrowEngine
//
//  Created by Simon Nilsson on 02/01/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#include "FAPointLight.h"

FAPointLight::FAPointLight() {
    intensity = 1;
    color = FAColorWhite;
    this->setScale(3);
}

void FAPointLight::setColor(glm::vec4 color) {
    this->color = color;
}

void FAPointLight::setShader(FAShader *shader) {
    this->shader = shader;
    
    glUseProgram(shader->shaderProgram);
    
    positionLocation = glGetAttribLocation(shader->shaderProgram, "in_Position");
    
    diffuseTextureUniform = glGetUniformLocation(shader->shaderProgram, "diffuseTexture");
    normalTextureUniform = glGetUniformLocation(shader->shaderProgram, "normalTexture");
    depthTextureUniform = glGetUniformLocation(shader->shaderProgram, "depthTexture");
    positionTextureUniform = glGetUniformLocation(shader->shaderProgram, "positionTexture");
    lightPositionUniform = glGetUniformLocation(shader->shaderProgram, "lightPosition");
    lightColorUniform = glGetUniformLocation(shader->shaderProgram, "lightColor");
    lightIntensityUniform = glGetUniformLocation(shader->shaderProgram, "lightIntensity");

    projectionMatrixLocation = glGetUniformLocation(this->shader->shaderProgram,"projectionMatrix");
    viewMatrixLocation = glGetUniformLocation(this->shader->shaderProgram, "viewMatrix");
    modelMatrixLocation = glGetUniformLocation(this->shader->shaderProgram, "modelMatrix");
    
//    modelMatrixLocation = glGetUniformLocation(shader->shaderProgram, "modelMatrix");
//    viewProjectionMatrixLocation = glGetUniformLocation(shader->shaderProgram, "viewProjectionMatrix");
    
    if(positionLocation == -1) {
        std::cout << "error positionLocation" << std::endl;
    }
    if(diffuseTextureUniform == -1) {
        std::cout << "error diffuseTextureUniform" << std::endl;
    }
    if(normalTextureUniform == -1) {
        std::cout << "error normalTextureUniform" << std::endl;
    }
    if(depthTextureUniform == -1) {
        std::cout << "error depthTextureUniform" << std::endl;
    }
    if(positionTextureUniform == -1) {
        std::cout << "error positionTextureUniform" << std::endl;
    }
    if(lightPositionUniform == -1) {
        std::cout << "error lightPositionUniform" << std::endl;
    }
    if(lightColorUniform == -1) {
        std::cout << "error lightColorUniform" << std::endl;
    }
    if(lightIntensityUniform == -1) {
        std::cout << "error lightIntensityUniform" << std::endl;
    }
//    if(modelMatrixLocation == -1) {
//        std::cout << "error modelMatrixLocation" << std::endl;
//    }
//    if(viewProjectionMatrixLocation == -1) {
//        std::cout << "error viewProjectionMatrixLocation" << std::endl;
//    }
    
    glUseProgram(0);
    
    glGenBuffers(1, &myVBO);
    glGenBuffers(1, &myEBO);
    glGenVertexArrays(1, &myVAO);
    
    std::vector<GLushort> indices = {
        0, 1, 2,
        0, 2, 3,
    };
    std::vector<GLfloat> vertices = {
        +1, +1,
        -1, +1,
        -1, -1,
        +1, -1
    };
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindVertexArray(myVAO);
    
    glEnableVertexAttribArray(positionLocation);
    
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    glVertexAttribPointer(positionLocation, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid *) (0 * sizeof(GLfloat)));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLushort), &indices[0], GL_STATIC_DRAW);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//    
//    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
//    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    
//    glBindVertexArray(myVAO);
//    
//    glEnableVertexAttribArray(positionLocation);
//    
//    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
//    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) (0 * sizeof(GLfloat)));
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
}

void FAPointLight::onRender(GLuint texures[4], FACamera *camera) {
    glBindVertexArray(myVAO);
    glDisable(GL_CULL_FACE);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texures[0]);
    
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texures[1]);
    
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, texures[2]);
    
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, texures[3]);
    
    glUseProgram(shader->shaderProgram);
//    glPointSize(100);
    
    glUniform1i(diffuseTextureUniform, 0);
    glUniform1i(normalTextureUniform, 1);
    glUniform1i(depthTextureUniform, 2);
    glUniform1i(positionTextureUniform, 3);
    glUniform4fv(lightPositionUniform, 1, &glm::vec4(this->position, 1)[0]);
    glUniform4fv(lightColorUniform, 1, &color[0]);
    glUniform1f(lightIntensityUniform, intensity);
    glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, &camera->projectionMatrix[0][0]);
    glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &camera->viewMatrix[0][0]);
    glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, &modelMatrix[0][0]);
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glUseProgram(0);

//    glActiveTexture(GL_TEXTURE0);
}

FAPointLight::~FAPointLight() {
    
}

//void FAPlane2D::onRender(FACamera *camera, GLuint texture, glm::mat4 textureMatrix) {
//    onRender(camera);
//}
//void FAPlane2D::onUpdate(float dt) {
//}
//
//FAPlane2D::~FAPlane2D() {
//    
//}