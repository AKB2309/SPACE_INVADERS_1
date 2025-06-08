#include "EnemyType3.h"
#include <cstdlib>

EnemyType3::EnemyType3(int x, int y) : Enemy(x, y, '&', GREEN, 1, 30) {} // direction = 1, points = 30

std::unique_ptr<Bullet> EnemyType3::tryShoot() {
    if (rand() % 40 == 0)
    {
        return std::make_unique<Bullet>(x, y + 1, 1, GREEN, '|');
    }
    return nullptr;
}

void EnemyType3::update() {
    Enemy::update();    

    if (rand() % 10 < 3) 
    {
        direction *= -1;
    }
}