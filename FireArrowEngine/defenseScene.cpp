#include "defenseScene.h"



defenseScene::defenseScene() {
}

void defenseScene::init() {
	setDisplayFps(false);
	path.push_back(glm::vec2(-50, 0));
	path.push_back(glm::vec2(-50, -50));
	path.push_back(glm::vec2(0, -50));
	path.push_back(glm::vec2(0, -25));
	path.push_back(glm::vec2(50, -25));

	delete camera;
	camera = new FACamera(40.0f, (float)windowWidth, windowHeigth, 1, 200);
	camera->setZ(60);
	camera->setY(55);
	camera->setX(0);
    camera->setRX(0.45);

	ground = new TDGround();
	ground->setSize(100,100);
	ground->setShader(shaders->getShader("Basic"));
	ground->setColor(FAColorDarkGreen);
	ground->setPos(glm::vec3(0,-1, -50));
	ground->setPath(&path);
	addChild(ground);

	addTower = new FAButton();
	addTower->setShader(shaders->getShader("Plane2D"));
	addTower->setColor(FAColorDarkRed);
	addTower->setSize(0.2,0.1);
	addTower->setID(1);
	addTower->setPos(glm::vec3(-0.9,0,1));
//    addTower->setPos(glm::vec3(0,0,0));
	addHUDElement(addTower);

//	FAFont *font = new FAFont("Helvetica.ttf", 20, windowWidth, windowHeigth);

	coins = new FAText2D(font);
	coins->setShader(shaders->getShader("Text2D"));
	coins->setText("Coins: 10c");
	coins->setPos(glm::vec3(-0.99, 0.95, 0));
	coins->setColor(FAColorWhite);
	addHUDElement(coins);
    
    FAText2D *t = new FAText2D(font);
    t->setShader(shaders->getShader("Text2D"));
    t->setText("price: 10c");
    t->setPos(glm::vec3(-0.95, -0.015, 0));
    t->setColor(FAColorWhite);
    addHUDElement(t);

	lives = new FAText2D(font);
	lives->setShader(shaders->getShader("Text2D"));
	lives->setText("Lives: 10");
	lives->setPos(glm::vec3(-0.99, 0.85, 0));
	lives->setColor(FAColorWhite);
	addHUDElement(lives);

	setCursorState(GLFW_CURSOR_NORMAL);
	glDisable(GL_CULL_FACE);
}

void defenseScene::update(float dt) {

	if (timer > 2) {
        if (spawedEnemies <= 100) {
		Enemy *m = new Enemy();
		m->setShader(shaders->getShader("BasicShadow"));
		m->setFAModel("cube.fa");
		m->setScale(1);
		m->setPos(glm::vec3(-50, 0, 0));
		m->setColor(FAColorBlue);
            m->setPath(&this->path);
            spawedEnemies++;
            health *= 1.05;
            m->setHealth(health);
		enemies.push_back(m);
		addChild(m);
		timer = 0;
        } else {
            if (enemies.size() == 0) {
            timer = -10000;
            FAText2D *t = new FAText2D(font);
            t->setShader(shaders->getShader("Text2D"));
            t->setText("Victory!");
            t->setPos(glm::vec3(-0, 0, 0));
            t->setColor(FAColorWhite);
            addHUDElement(t);
            }
        }
	}
	timer += dt;
	Enemy *enemy;
	for (int i = 0; i < enemies.size(); i++) {
		enemy = enemies[i];
		if (enemy->getHealth() <= 0) {
			enemies.erase(enemies.begin() + i);
			enemy->getParent()->removeNode(enemy);
			delete enemy;
			i--;
			numberOfCoins++;
			coins->setText("Coins: " +std::to_string(numberOfCoins) + "c");
		} else {
			if (!enemy->calculateMove(dt * 3)) {
				enemies.erase(enemies.begin() + i);
				enemy->getParent()->removeNode(enemy);
				delete enemy;
				i--;
				numberOfLives--;
				lives->setText("Lives: " + std::to_string(numberOfLives));
				if (numberOfLives <= 0) {
					timer = -10000;
//					FAFont *font = new FAFont("Helvetica.ttf", 40, windowWidth, windowHeigth);

					FAText2D *t = new FAText2D(font);
					t->setShader(shaders->getShader("Text2D"));
					t->setText("Game Over!");
					t->setPos(glm::vec3(-0, 0, 0));
					t->setColor(FAColorWhite);
					addHUDElement(t);

					delete font;
				}
			}
		}
	}

	//override
	camera->moveX(cameraMovement.z * dt * sin(camera->getRY()));
	camera->moveZ(-cameraMovement.z * dt * cos(camera->getRY()));

	camera->moveX(cameraMovement.x * dt * cos(camera->getRY()));
	camera->moveZ(cameraMovement.x * dt * sin(camera->getRY()));
	camera->moveY(cameraMovement.y * dt);

	children->update(dt);
	for (FAScene *scene : subviews)
		scene->update(dt);
	for (FANode *node : HUDElements)
		node->update(dt);
}

void defenseScene::render() {
	camera->useView();
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	children->render(camera);

	glClear(GL_DEPTH_BUFFER_BIT);

	for (FANode* node : HUDElements)
		node->render(HUDcamera);
}

void defenseScene::getKeyInput(int key, int action) {
	if (key == GLFW_KEY_W) {
		if (action == GLFW_PRESS) {
			cameraMovement.z += speed;
		} else if (action == GLFW_RELEASE) {
			cameraMovement.z -= speed;
		}
	} else if (key == GLFW_KEY_S) {
		if (action == GLFW_PRESS) {
			cameraMovement.z -= speed;
		} else if (action == GLFW_RELEASE) {
			cameraMovement.z += speed;
		}
	} else if (key == GLFW_KEY_D) {
		if (action == GLFW_PRESS) {
			cameraMovement.x += speed;
		} else if (action == GLFW_RELEASE) {
			cameraMovement.x -= speed;
		}
	} else if (key == GLFW_KEY_A) {
		if (action == GLFW_PRESS) {
			cameraMovement.x -= speed;
		} else if (action == GLFW_RELEASE) {
			cameraMovement.x += speed;
		}
	} else if (key == GLFW_KEY_SPACE) {
		if (action == GLFW_PRESS) {
			cameraMovement.y += speed;
		} else if (action == GLFW_RELEASE) {
			cameraMovement.y -= speed;
		}
	} else if (key == GLFW_KEY_DOWN) {
		if (action == GLFW_PRESS) {
			factor -= 0.1;
		}
	} else if (key == GLFW_KEY_UP) {
		if (action == GLFW_PRESS) {
			factor += 0.1;
		}
	} else if (key == GLFW_KEY_LEFT) {
		if (action == GLFW_PRESS) {
			units -= 0.1;
		}
	} else if (key == GLFW_KEY_RIGHT) {
		if (action == GLFW_PRESS) {
			units += 0.1;
		}
	} else if (key == GLFW_KEY_LEFT_SHIFT) {
		if (action == GLFW_PRESS) {
			cameraMovement.y -= speed;
		} else if (action == GLFW_RELEASE) {
			cameraMovement.y += speed;
		}
	} else if (key == GLFW_KEY_ESCAPE) {
		if (action == GLFW_PRESS) {
			if (getCursorState() == GLFW_CURSOR_NORMAL) {
				setCursorState(GLFW_CURSOR_DISABLED);
			} else {
				setCursorState(GLFW_CURSOR_NORMAL);
			}
		}
	} else {
		std::cout << "Key: " << key << " action: " << action << std::endl;
	}
}

float distanceBetweenLineAndPoint(glm::vec2 p1, glm::vec2 p2, glm::vec2 p3) {
	float l2 = pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);

	if (l2 == 0) return glm::distance(p1, p3);
	float t = glm::dot(p3 - p1, p2 - p1) / l2;
	if (t < 0.0f) return glm::distance(p1, p3);
	else if (t > 1.0) return glm::distance(p3, p2);
	glm::vec2 projection = p1 + t * (p2 - p1);
	return glm::distance(p3, projection);

}

void defenseScene::mouseKeyInput(int button, int action) {
	if (button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS) {
		if (placeTower) {
			if (numberOfCoins >= 10) {
				glm::mat4 viewMatrix = glm::rotate(glm::mat4(), camera->getRX(), glm::vec3(1, 0, 0));
				viewMatrix = glm::rotate(viewMatrix, camera->getRY(), glm::vec3(0, 1, 0));
				viewMatrix = glm::rotate(viewMatrix, camera->getRZ(), glm::vec3(0, 0, 1));
				glm::mat4 viewProjectionInverseMatrix = glm::inverse(camera->projectionMatrix * viewMatrix);
				glm::vec4 direction = viewProjectionInverseMatrix * glm::vec4((previousCursorPosition.x / windowWidth) * 2 - 1, 1 - (previousCursorPosition.y / windowHeigth) * 2, 1, 1);
				glm::vec3 dir = glm::vec3(direction);

				float n = -camera->getY() / dir.y;
				glm::vec3 intersection = camera->getPosition() + n * dir;

				bool collide = false;
				if (intersection.x > -50 && intersection.x < 50) {
					if (intersection.z > -100 && intersection.z < 0) {
						//test if ther is not a enemy or tower already.
						glm::vec2 p2;
						for (int i = 1; i < path.size(); i++) {
							float distance = distanceBetweenLineAndPoint(path[i], path[i - 1], glm::vec2(intersection.x, intersection.z));
							if (distance < 4) {
								collide = true;
							}
						}
						for (Tower *t : towers) {
							if (glm::distance(t->getPos(), intersection) < 4) {
								collide = true;
							}
						}
						if (!collide) {
							Tower *m = new Tower();
							m->setShader(shaders->getShader("BasicShadow"));
							m->setFAModel("cube.fa");
							m->setScale(1);
							m->setPos(intersection);
							m->setColor(FAColorDarkRed);
							m->setEnemies(&enemies);
							m->setRange(50);
                            placeTower = false;
                            addTower->setColor(FAColorDarkRed);
							addChild(m);
							towers.push_back(m);
							numberOfCoins -= 10;
							coins->setText("Coins: " + std::to_string(numberOfCoins) + "c");
						}
					}
				}
			}
		}
	}
}

void defenseScene::cursorPosition(double x, double y) {

	//calculated from the uppear left corner
	glm::vec2 currentCursorPos = glm::vec2(x, y);
	glm::vec2 deltaCursorPos = currentCursorPos - previousCursorPosition;
	previousCursorPosition = currentCursorPos;
	if (!cursorHasMoved) {
		if (previousCursorPosition != glm::vec2()) {
			cursorHasMoved = true;
			return;
		}
	}
	if (getCursorState() == GLFW_CURSOR_DISABLED) {
		camera->rotateY(deltaCursorPos.x / 1000.0f);
		camera->rotateX(deltaCursorPos.y / 1000.0f);
	}

}

void defenseScene::buttonPressed(FAHUDElement *node) {
	if (getCursorState() == GLFW_CURSOR_NORMAL) {
		switch (node->getID()) {
		case 1: {
			//addTower:
            if (numberOfCoins >= 10) {
                placeTower = !placeTower;
                if (!placeTower) {
                    FAButton *b = (FAButton *)node;
                    b->setColor(FAColorDarkRed);
                } else {
                    FAButton *b = (FAButton *)node;
                    b->setColor(FAColorRed);
                }
            }
			break;
		}
		default:
			break;
		}
	}
}

defenseScene::~defenseScene() {

}
