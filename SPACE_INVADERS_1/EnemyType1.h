#pragma once
#include "Enemy.h"

class EnemyType1 : public Enemy {
public:
	EnemyType1(int x, int y);
	void update() override;
};