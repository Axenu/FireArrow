#pragma once
#include "FAScene.h"
#include "FAPlane3D.h"
#include "FAModel.h"
#include "Enemy.h"
#include "FAButton.h"
#include "FALine.h"
#include "FAText2D.h"
#include "Tower.h"
#include "TDGround.h"

class defenseScene : public FAScene {

private: 
	TDGround *ground;
	FAText2D *coins;
	FAText2D *lives;
    FAButton *addTower;
	std::vector<Enemy *> enemies;
	std::vector<Tower *> towers;
	std::vector<glm::vec2> path;
	int numberOfCoins = 10;
	int numberOfLives = 10;
    int spawedEnemies = 0;
    float health = 10;

	double timer = 10;
	const float speed = 15;
	bool cursorHasMoved = false;
	glm::vec2 previousCursorPosition;
	glm::vec3 cameraMovement;
		float factor = 0.5;
		float units = 0;

		bool placeTower = false;

public:
	defenseScene();

	void init();
		void update(float dt);
		void render();
		void getKeyInput(int key, int action);
		void mouseKeyInput(int button, int action);
		void cursorPosition(double x, double y);
		void buttonPressed(FAHUDElement *node);

	~defenseScene();
};

