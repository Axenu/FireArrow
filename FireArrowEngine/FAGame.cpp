//
//  FAGame.cpp
//  FireArrow
//
//  Created by Simon Nilsson on 13/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#include "FAGame.h"

FAGame::FAGame() {
    initEngine();
}

void FAGame::init() {
    
}

FAScene* FAGame::setInitialScene() {
    return new testScene();
}

void FAGame::setWindowAttributes() {
    this->setWindowsSize(1240, 720);
    this->setSamples(4);
    this->setDecorated(false);
//    this->setWindowColor(glm::vec3(95.0/255.0,62.0/255.0,39.0/255.0));
}

FAGame::~FAGame() {
    
}