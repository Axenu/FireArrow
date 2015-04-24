//
//  mat4.h
//  FireArrow
//
//  Created by Simon Nilsson on 13/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__mat4__
#define __FireArrow__mat4__

#include <iostream>
#include "vec3.h"

namespace fa {

	class mat4 {
	private:
		double value[4][4];
	public:
		mat4();
		mat4 rotate(mat4 m, double angle, vec3 v);
		void print();
	};
}

#endif