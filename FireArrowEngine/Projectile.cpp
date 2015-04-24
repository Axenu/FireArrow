#include "Projectile.h"



Projectile::Projectile() {
	speed = 25;
	damage = 10;
	range = 50;
}

void Projectile::setDirection(glm::vec3 d) {
	this->direction = glm::normalize(d);
}

glm::vec3 Projectile::getNextPosition(double dt) {
	return this->position + direction * (float)(speed * dt);
}

void Projectile::setDamage(float damage) {
	this->damage = damage;
}

void Projectile::setRange(float range) {
	this->range = range;
}

float Projectile::getDamage() {
	return this->damage;
}

float Projectile::getRange() {
	return this->range;
}

Projectile::~Projectile() {
}

void Projectile::onUpdate(float dt) {
	move(direction * (float)(speed * dt));
}
