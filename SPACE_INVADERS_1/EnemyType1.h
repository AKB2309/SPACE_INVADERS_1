#pragma once
#include "Enemy.h"

class EnemyType1 : public Enemy {
public:
	EnemyType1(int x, int y);
	std::unique_ptr<Bullet> tryShoot() override;
	void update(int playerY) override;
};