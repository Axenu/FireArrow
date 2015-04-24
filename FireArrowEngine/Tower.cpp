#include "Tower.h"



Tower::Tower() {
	projectiles = new std::vector<Projectile *>();
	this->fireRate = 1;
	this->range = 50;
}

void Tower::setEnemies(std::vector<Enemy *> *enemies) {
	this->enemies = enemies;
}

void Tower::setRange(float range) {
	this->range = range;
}

std::vector<Enemy *> *Tower::getEnemies() {
	return enemies;
}

float Tower::distanceBetweenLineAndPoint(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3) {
	float l2 = glm::length2(p1 - p2);

	if (l2 == 0) return glm::distance(p1, p3);
	float t = glm::dot(p3 - p1, p2 - p1) / l2;
	if (t < 0.0f) return glm::distance(p1, p3);
	else if (t > 1.0) return glm::distance(p3, p2);
	glm::vec3 projection = p1 + t * (p2 - p1);
	return glm::distance(p3, projection);

}

void Tower::onUpdate(float dt) {
	if (timer > 1.0/fireRate) {
		//fire projectile
		if (this->enemies->size() > 0) {
			int index = 0;
			float distance = glm::length(this->position - (*enemies)[0]->getPos());
			for (int i = 1; i < enemies->size(); i++) {
				float d = glm::length(this->position - (*enemies)[i]->getPos());
				if (d < distance) {
					distance = d;
					index = i;
				}
			}
			if (distance < this->range) {
				Projectile *p = new Projectile();
				p->setShader(this->shader);
				p->setFAModel("cube.fa");
				p->setScale(0.1);
				p->setColor(FAColorGreen);
				p->setDirection(((*enemies)[index]->getPos() - this->position));
				p->setRange(this->range);
				projectiles->push_back(p);
				addNode(p);
				timer = 0;
			}
		}
	}
	timer += dt;
	for (int i = 0; i < projectiles->size(); i++) {
		Projectile *p = (*projectiles)[i];
		if (glm::length(p->getPos()) > p->getRange()) {
			projectiles->erase(projectiles->begin() + i);
			p->getParent()->removeNode(p);
			i--;
			delete p;
		} else {
			for (Enemy *e : *enemies) {
				glm::vec3 p1 = e->getPos();
				glm::vec3 p2 = p->getNextPosition(dt) + this->position;
				glm::vec3 p3 = p->getPos() + this->position;
				float distance = distanceBetweenLineAndPoint(p2, p3, p1);
				if (distance < 0) {
					break;
				}
				if (distance < 2) {
					//hit enemie
					e->takeDamage(p->getDamage());
					projectiles->erase(projectiles->begin() + i);
					p->getParent()->removeNode(p);
					i--;
					delete p;
				}
			}
		}
	}
}

Tower::~Tower() {
	delete projectiles;
}
