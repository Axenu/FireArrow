#include "TDGround.h"



TDGround::TDGround() {
}

float TDGround::distanceBetweenLineAndPoint(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3) {
	float l2 = pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);

	if (l2 == 0) return glm::distance(p1, p3);
	float t = glm::dot(p3 - p1, p2 - p1) / l2;
	if (t < 0.0f) return glm::distance(p1, p3);
	else if (t > 1.0) return glm::distance(p3, p2);
	glm::vec2 projection = p1 + t * (p2 - p1);
	return glm::distance(p3, projection);

}

void TDGround::setPath(std::vector<glm::vec2> *path) {
	this->path = path;
	//display path!
	for (int i = 1; i < path->size(); i++) {
		glm::vec2 p1 = (*path)[i - 1];
		glm::vec2 p2 = (*path)[i];
		glm::vec2 p3 = p2 - p1;
		float angle = std::atan2(p3.x, p3.y) - glm::pi<float>();
		float length = glm::length(p3);
		FAPlane3D *p = new FAPlane3D();
//		if (path->size() > i+1) {
//			float nextAngle = std::atan2(((*path)[i+1].x- (*path)[i].x), ((*path)[i + 1].y- (*path)[i].y)) - glm::pi<float>();
//			if (nextAngle > angle) {
// 				p->setSize(5, length + 5);
//			} else {
//				p->setSize(5, length);
//			}
//		} else {
			p->setSize(5, length + 5);
//		}
		p->setShader(this->shader);
		p->setColor(FAColorRed);
		p->setRY(angle);
        print(angle);
		p->setPos((glm::vec3((p1.x + p2.x)/2, -0.9, (p1.y + p2.y)/2) - this->position));
		addNode(p);
	}
	std::vector<FAModel *> *trees = new std::vector<FAModel *>();
	FAShader *treeShader = new FAShader("FADirectional");
//	FAModel *t = new FAModel();
//	t->setShader(s);
//	t->setFAModel("tree.fa");
//	t->setPos(glm::vec3(0, 0, 0));
//	t->setColor(FAColorPurple);
//	addNode(t);
//	trees->push_back(t);
	for (int i = 0; i < 50; i++) {
		bool collide = false;
		glm::vec2 treePoint = glm::vec2(rand() % 100 - 50, -(rand() % 100 - 50));
		for (int j = 1; j < path->size(); j++) {
            float distance = distanceBetweenLineAndPoint((*path)[j], (*path)[j - 1], treePoint - glm::vec2(50,50));
			if (distance < 4) {
				collide = true;
			}
		}
		for (FAModel *t : *trees) {
			if (glm::distance(t->getPos(), glm::vec3(treePoint.x, 0, treePoint.y)) < 4) {
				collide = true;
			}
		}
		if (!collide) {
            FAModel *t = new FAModel();
            t->setShader(treeShader);
            t->setFAModel("tree.fa");
            t->setPos(glm::vec3(treePoint.x, 0, treePoint.y));
            t->setColor(FAColorPurple);
            addNode(t);
			trees->push_back(t);
		}
	}
	delete trees;
}

TDGround::~TDGround() {
    delete treeShader;
}
