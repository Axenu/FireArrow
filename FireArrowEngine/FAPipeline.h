//
//  FAPipeline.h
//  FireArrowEngine
//
//  Created by Simon Nilsson on 24/04/15.
//  Copyright (c) 2015 Axenu. All rights reserved.
//

#ifndef __FireArrowEngine__FAPipeline__
#define __FireArrowEngine__FAPipeline__

#include <stdio.h>
#include "FANode.h"
#include "FACamera.h"

class FAPipeline {
    
    
public:
    void render(FACamera *camera, FANode *children);
};

#endif /* defined(__FireArrowEngine__FAPipeline__) */
