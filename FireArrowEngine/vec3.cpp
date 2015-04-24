#include "vec3.h"

namespace fa {

	vec3::vec3() {

	}

	vec3::vec3(vec3 &v) {
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}

	vec3::vec3(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	double vec3::dot(vec3 v, vec3 c) {
		return v.x*c.x + v.y*c.y + v.z*c.z;
	}

	double vec3::length(vec3 v) {
		sqrt(dot(v, v));
	}

	vec3 vec3::normalize(vec3 v) {
		double len = length(v);
		return vec3(v.x/len, v.y/len, v.z/len);
	}

	vec3 vec3::operator*(const double d) {
		return vec3(this->x * d, this->y*d, this->z*d);
	}

	vec3 operator*(double d, const vec3 &v) {
		return d*v;
	}
}