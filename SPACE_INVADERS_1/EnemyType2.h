#pragma once
#include "Enemy.h"

class EnemyType2 : public Enemy {
public:
	EnemyType2(int x, int y);
	void update() override;
};

