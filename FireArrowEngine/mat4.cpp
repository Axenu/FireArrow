#include "mat4.h"

namespace fa {

	mat4::mat4() {
		value[0][0] = 1;
		value[0][1] = 0;
		value[0][2] = 0;
		value[0][3] = 0;
		value[1][0] = 0;
		value[1][1] = 1;
		value[1][2] = 0;
		value[1][3] = 0;
		value[2][0] = 0;
		value[2][1] = 0;
		value[2][2] = 1;
		value[2][3] = 0;
		value[3][0] = 0;
		value[3][1] = 0;
		value[3][2] = 0;
		value[3][3] = 1;
	}

	void mat4::print() {
		std::cout << "fa::mat4: " << std::endl;
		std::cout << value[0][0] << ", " << value[0][1] << ", " << value[0][2] << ", " << value[0][3] << ", " << std::endl;
		std::cout << value[1][0] << ", " << value[1][1] << ", " << value[1][2] << ", " << value[1][3] << ", " << std::endl;
		std::cout << value[2][0] << ", " << value[2][1] << ", " << value[2][2] << ", " << value[2][3] << ", " << std::endl;
		std::cout << value[3][0] << ", " << value[3][1] << ", " << value[3][2] << ", " << value[3][3] << ", " << std::endl;

	}

	mat4 mat4::rotate(mat4 m, double angle, vec3 v) {
		double const a = angle;
		double const c = cos(a);
		double const s = sin(a);

		vec3 axis(normalize(v));
		vec3 temp((1.0 - c) * axis);

		mat4 Rotate();
		Rotate[0][0] = c + temp[0] * axis[0];
		Rotate[0][1] = 0 + temp[0] * axis[1] + s * axis[2];
		Rotate[0][2] = 0 + temp[0] * axis[2] - s * axis[1];

		Rotate[1][0] = 0 + temp[1] * axis[0] - s * axis[2];
		Rotate[1][1] = c + temp[1] * axis[1];
		Rotate[1][2] = 0 + temp[1] * axis[2] + s * axis[0];

		Rotate[2][0] = 0 + temp[2] * axis[0] + s * axis[1];
		Rotate[2][1] = 0 + temp[2] * axis[1] - s * axis[0];
		Rotate[2][2] = c + temp[2] * axis[2];

		mat4 Result();
		Result[0] = m[0] * Rotate[0][0] + m[1] * Rotate[0][1] + m[2] * Rotate[0][2];
		Result[1] = m[0] * Rotate[1][0] + m[1] * Rotate[1][1] + m[2] * Rotate[1][2];
		Result[2] = m[0] * Rotate[2][0] + m[1] * Rotate[2][1] + m[2] * Rotate[2][2];
		Result[3] = m[3];
		return Result;
	}
}