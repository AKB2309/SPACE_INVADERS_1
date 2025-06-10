#pragma once
#include "Enemy.h"

class EnemyType3 : public Enemy {
public:
	EnemyType3(int x, int y);
	std::unique_ptr<Bullet> tryShoot() override;
	void update(int playerY) override;
};

