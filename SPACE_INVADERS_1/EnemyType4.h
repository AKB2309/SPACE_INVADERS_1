#pragma once
#include "Enemy.h"

class EnemyType4 : public Enemy {
public:
	EnemyType4(int x, int y);
	std::unique_ptr<Bullet> tryShoot() override;
	void update(int playerY) override;
};