#include "EnemyType4.h"
#include <cstdlib>

EnemyType4::EnemyType4(int x, int y) : Enemy(x, y, '$', PURPLE, 0, 40) {} // points = 40

std::unique_ptr<Bullet> EnemyType4::tryShoot() {
    if (rand() % 25 == 0) 
    {
        return std::make_unique<Bullet>(x, y + 1, 1, PURPLE, '|');
    }
    return nullptr;
}

void EnemyType4::update() {
    Enemy::update();

    if (rand() % 100 < 5) {
        direction = (rand() % 2) ? 2 : -2;
    }   
}