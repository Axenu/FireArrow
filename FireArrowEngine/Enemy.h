#pragma once
#include "FAModel.h"
class Enemy : public FAModel {

private:
	std::vector<glm::vec2> *path;
	float health;
	float speed;
	int nextPoint = 0;

public:
	Enemy();

	void setPath(std::vector<glm::vec2> *path);
	void setHealth(float health);
	void setSpeed(float speed);
	float getHealth();
	bool calculateMove(double dt);
	void takeDamage(float damage);

	~Enemy();
};

