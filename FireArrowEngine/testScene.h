//
//  testScene.h
//  FireArrowEngine
//
//  Created by Simon Nilsson on 25/03/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#ifndef __FireArrowEngine__testScene__
#define __FireArrowEngine__testScene__

#include <stdio.h>
#include <iostream>
#include <CoreFoundation/CoreFoundation.h>
#include "FAScene.h"
#include "FAMaterial.h"
#include "FATexturedPlane2D.h"

class testScene : public FAScene {
    
private:
    FATexturedPlane2D *albumArt;
    
public:
    void init();
//    void render();
    void renderShadow();
    void update(float dt);
    //    using FAScene::getKeyInput;
    void buttonPressed(int index);
    void getKeyInput(int key, int action);
    void mouseKeyInput(int button, int action);
    void cursorPosition(double x, double y);
    
};

#endif /* defined(__FireArrowEngine__testScene__) */
