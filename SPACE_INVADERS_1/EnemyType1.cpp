#include "EnemyType1.h"
#include <cstdlib>
#include <algorithm>

EnemyType1::EnemyType1(int x, int y) : Enemy(x, y, '@', LIGHT_RED, 1, 10, 1, 40, 1) {} // points = 10

std::unique_ptr<Bullet> EnemyType1::tryShoot() {  
    return Enemy::tryShoot();
}

void EnemyType1::update(int playerY) {
	Enemy::update(playerY);
}