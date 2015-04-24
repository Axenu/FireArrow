#pragma once
#include "FAModel.h"
#include "FAPlane3D.h"
class TDGround : public FAPlane3D {

private:
	std::vector<glm::vec2> *path;
    FAShader *treeShader;

	float distanceBetweenLineAndPoint(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3);

public:
	TDGround();

	void setPath(std::vector<glm::vec2> *path);

~TDGround();
};

