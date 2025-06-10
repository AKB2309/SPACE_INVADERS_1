#pragma once
#include "Enemy.h"

class EnemyType2 : public Enemy {
public:
	EnemyType2(int x, int y);
	std::unique_ptr<Bullet> tryShoot() override;
	void update(int playerY) override;
};

