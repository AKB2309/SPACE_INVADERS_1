#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ConsoleArea.h"
#include <vector>
#include <memory>
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
	bool checkCollisionGameObjects(GameObject& obj, GameObject& obj2);
	


	std::vector<GameObject*> bullets;

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
