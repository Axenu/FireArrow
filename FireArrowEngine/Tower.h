#pragma once
#include "FAModel.h"
#include "Enemy.h"
#include "Projectile.h"
class Tower : public FAModel {

private:
	float damage;
	float fireRate;
	float range;
	double timer = 0;
	std::vector<Enemy *> *enemies;
	std::vector<Projectile *> *projectiles;

public:
	Tower();

	void setEnemies(std::vector<Enemy *> *enemies);
	void setRange(float range);
	std::vector<Enemy *> *getEnemies();
	float distanceBetweenLineAndPoint(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);

	~Tower();

	virtual void onUpdate(float dt);
};

