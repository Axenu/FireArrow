#pragma once
#include "FAModel.h"
class Projectile : public FAModel {

private:
	float damage;
	float range;
	float speed;
	glm::vec3 direction;
	glm::vec3 startingPosition;

public:
	Projectile();

	void setDirection(glm::vec3 d);
	void setDamage(float damage);
	void setRange(float range);
	float getDamage();
	float getRange();
	glm::vec3 getNextPosition(double dt);

	~Projectile();

	virtual void onUpdate(float dt);
};

