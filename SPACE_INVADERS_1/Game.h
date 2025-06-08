#pragma once
#include "Player.h"
#include "Enemy.h"
#include "EnemyType1.h"
#include "EnemyType2.h"
#include "EnemyType3.h"
#include "EnemyType4.h"
#include "Bullet.h"
#include "ConsoleArea.h"
#include <vector>
#include <memory>


class Game 
{
 protected:

	Player player;
	bool running;

	std::vector<GameObject*> bullets;
	std::vector<Enemy*> enemies;

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
