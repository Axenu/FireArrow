//
//  vec3.h
//  FireArrow
//
//  Created by Simon Nilsson on 13/01/14.
//  Copyright (c) 2014 Axenu. All rights reserved.
//

#ifndef __FireArrow__vec3__
#define __FireArrow__vec3__

#include <iostream>

namespace fa {

	class vec3 {
	private:
		double x,y,z;
	public:
		vec3();
		vec3(vec3 &v);
		vec3(double x, double y, double z);
		static double dot(vec3 v, vec3 c);
		static double length(vec3 v);
		static vec3 normalize(vec3 v);
		void print();

		//operators
		vec3 operator*(const vec3 v);
		vec3 operator*(double d);
		friend vec3 operator*(double d, const vec3 &v);

	};
}

#endif