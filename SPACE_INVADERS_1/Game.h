#pragma once
#include <vector>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "EnemyType1.h"
#include "EnemyType2.h"
#include "EnemyType3.h"
#include "EnemyType4.h"
#include "Bullet.h"
#include "ConsoleArea.h"
#include "visualization.h"

class Game
{
protected:

	Player player;
	bool running;
	int score;
	int level;
	std::string status;

	void checkBulletEnemyCollisions();
	void checkPlayerEnemyCollisions();
	void checkBulletPlayerCollisions();
	bool checkCollisionGameObjects(GameObject& obj, GameObject& obj2, int range = 0);



	std::vector<GameObject*> bullets;
	std::vector<Enemy*> enemies;

	void updateLevel();
	void initializeEnemies();
	void input();
	void update();
	void checkCollisions();
	void render();


public:

	Game();
	~Game();

	void run();

};
