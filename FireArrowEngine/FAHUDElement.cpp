//
//  FAHUDElement.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 26/12/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAHUDElement.h"

FAHUDElement::FAHUDElement() {
    isClickable = true;
}

void FAHUDElement::setID(int id) {
    this->id = id;
}
int FAHUDElement::getID() {
    return this->id;
}

void FAHUDElement::setX(float x) {
    this->FANode::setX(x);
    this->bbPosition.x = x - anchorPoint.x*size.width*2;
    calculateMaxAndMin();
}
void FAHUDElement::setY(float y) {
    this->FANode::setY(y);
    this->bbPosition.y = y - anchorPoint.y*size.height*2;
    calculateMaxAndMin();
}
void FAHUDElement::setPos(glm::vec3 pos) {
    this->FANode::setPos(pos);
    this->bbPosition = glm::vec2((pos.x + 1)/2, (pos.y + 1)/2);
    calculateMaxAndMin();
}

void FAHUDElement::onUpdate(float dt) {
    
}

bool FAHUDElement::handleClick(glm::vec2 p) {
    
    if (collideWith(p)) {
        if (isClickable) {
            
        }
        return true;
    }
    return false;
}

FAHUDElement::~FAHUDElement() {
    
}