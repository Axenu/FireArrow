#include "Enemy.h"



Enemy::Enemy() {
	this->speed = 1;
	this->health = 10;
}

void Enemy::setPath(std::vector<glm::vec2> *path) {
	this->path = path;
}

void Enemy::setHealth(float health) {
	this->health = health;
}

void Enemy::setSpeed(float speed) {
	this->speed = speed;
}

float Enemy::getHealth() {
	return this->health;
}

bool Enemy::calculateMove(double dt) {

	if (nextPoint < path->size()) {
		glm::vec2 direction = this->path->at(nextPoint) - glm::vec2(this->position.x, this->position.z);
		float distance = glm::length(direction);
		if (distance < dt * speed) {
			//do the move then call move again with the rest of the time.
			this->setX(this->path->at(nextPoint).x);
			this->setZ(this->path->at(nextPoint).y);
			double rest = (dt * speed) - distance;
			this->nextPoint++;
			return this->calculateMove(rest);
		}
		direction = glm::normalize(direction);
		this->moveX(direction.x * dt * speed);
		this->moveZ(direction.y * dt * speed);
				return true;
	}
	return false;
}

void Enemy::takeDamage(float damage) {
	this->health -= damage;
}

Enemy::~Enemy() {
}
