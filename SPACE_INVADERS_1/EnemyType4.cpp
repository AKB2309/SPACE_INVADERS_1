#include "EnemyType4.h"
#include <cstdlib>

EnemyType4::EnemyType4(int x, int y) : Enemy(x, y, '$', PURPLE, 1, 40, 1, 40, 1) {} // points = 40

std::unique_ptr<Bullet> EnemyType4::tryShoot() {
    return Enemy::tryShoot();
}

void EnemyType4::update(int playerY) {
    Enemy::update(playerY);
}