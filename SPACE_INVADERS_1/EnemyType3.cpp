#include "EnemyType3.h"
#include <cstdlib>

EnemyType3::EnemyType3(int x, int y) : Enemy(x, y, '&', LIGHT_GREEN, 1, 30, 1, 40, 1) {} // points = 30

std::unique_ptr<Bullet> EnemyType3::tryShoot() {
    return Enemy::tryShoot();
}

void EnemyType3::update(int playerY) {
    Enemy::update(playerY);
}