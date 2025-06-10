#include "EnemyType2.h"

EnemyType2::EnemyType2(int x, int y) : Enemy(x, y, '#', YELLOW, 1, 20, 1, 40, 1) {} // points = 20 

std::unique_ptr<Bullet> EnemyType2::tryShoot() {    
    return Enemy::tryShoot();
}

void EnemyType2::update(int playerY) {
	Enemy::update(playerY);
}