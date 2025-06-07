#pragma once
#include "Player.h"
#include "Enemy.h"
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
