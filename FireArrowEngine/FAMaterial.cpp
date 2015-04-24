//
//  FAMaterial.cpp
//  FireArrowEngine
//
//  Created by Simon Nilsson on 25/03/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#include "FAMaterial.h"

FAMaterial::FAMaterial() {
    version = 400;
    hasVertexNormal = true;
    hasVertexColor = true;
}

void FAMaterial::init() {
    std::string frag, vert;
    stringstream ss;
    
    //shadow
    if (hasShadow) {
        ss << "#version " << version << " core" << endl;
        ss << "uniform mat4 modelViewProjectionMatrix;" << endl;
        ss << "void main() {" << endl;
        ss << "gl_Position = modelViewProjectionMatrix * vec4(in_Position, 1.0);" << endl;
        ss << "}";
        vert = ss.str();
        ss.str("");
        ss << "#version " << version << " core" << endl;
        ss << "void main() {" << endl;
        ss << "}";
        frag = ss.str();
        ss.str("");
        shadowShader = new FAShader(vert, frag);
    }
    
    ss << "#version " << version << " core" << endl;
    ss << "in vec3 in_Position;" << endl;
    if (hasVertexNormal)
        ss << "in vec3 in_Normal;" << endl;
    if (hasVertexColor)
        ss << "in vec4 in_Color;" << endl;
    if (hasVertexUV)
        ss << "in vec2 in_UV;" << endl;
    for (FAUniform *u : uniforms) {
        ss << u->toString();
    }
    if (hasGlobalLight) {
        ss << "uniform mat4 modelMatrix;" << endl;
    }
    if (hasVertexColor) {
        ss << "out vec4 pass_Color;" << endl;
    }
    if (hasVertexNormal) {
    if (hasGlobalLight) {
        ss << "out vec3 pass_Normal;" << endl;
    }
    }
    
    ss << "uniform mat4 modelViewProjectionMatrix;" << endl;
    
    ss << "void main() {" << endl;
    if (hasVertexNormal) {
        if (hasGlobalLight) {
            ss << "pass_Normal = (modelMatrix * vec4(in_Normal,0)).xyz;" << endl;
        }
    }
    if (hasVertexColor) {
        ss << "pass_Color = in_Color;" << endl;
    }
    ss << "gl_Position = modelViewProjectionMatrix * vec4(in_Position, 1.0);" << endl;
    ss << "}";
    vert = ss.str();
//    cout << vert << endl;
    ss.str("");
    
    //fragment
    
    ss << "#version " << version << " core" << endl;
    
    if (hasVertexColor) {
        ss << "in vec4 pass_Color;" << endl;
    }
    if (hasVertexNormal) {
        if (hasGlobalLight) {
            ss << "in vec3 pass_Normal;" << endl;
        }
    }
    
    ss << "out vec4 frag_data;" << endl;
    
    for (FAUniform *u : uniforms) {
        ss << u->toString();
    }
    
    ss << "void main() {" << endl;
    
    if (hasGlobalLight) {
        ss << "float ambientComponent = 0.5;" << endl;
        ss << "const vec3 diffuseColor = vec3(0.5, 0.5, 0.5);" << endl;
        ss << "vec3 normal = normalize(pass_Normal);" << endl;
        ss << "vec3 lightDir = normalize(-vec3(1,-1,1));" << endl;
        ss << "float lambertian = max(dot(lightDir,normal), 0.0);" << endl;
    }
    
    ss << "frag_data = ";
    if (hasVertexColor) {
        ss << "pass_Color * ";
    }
    if (hasVertexNormal) {
        if (hasGlobalLight) {
            ss << "(ambientComponent + lambertian)";
        }
    }
    ss << ";" << endl;
    ss << "frag_data.w = 1.0;" << endl;
    ss << "}" << endl;
    
    frag = ss.str();
    
    shader = new FAShader(vert, frag);
}

void FAMaterial::setTexture(GLint texture) {
    this->texture = texture;
}

void FAMaterial::setColor(glm::vec4 color) {
    this->color = color;
    FAUniformVec4 *u = new FAUniformVec4(&colorAttributeLocation, "color", &this->color);
    uniforms.push_back(u);
    for (FAUniform *u : uniforms) {
        u->setUniform();
    }

}

void FAMaterial::setGlobalLight() {
    
    hasGlobalLight = true;
    
}

//void render() {
//    for (FAUniform *u : uniforms) {
//        u->setUniform();
//    }
//}

FAMaterial::~FAMaterial() {
    
}