#include "EnemyType1.h"
#include <cstdlib>
#include <algorithm>

EnemyType1::EnemyType1(int x, int y) : Enemy(x, y, '@', LIGHT_RED, 1, 10) {} // direction = 1, points = 10

void EnemyType1::update() {
	Enemy::update();

    if (rand() % 100 < 10) {
        int delta = (rand() % 3) - 1;
        x += delta;

        if (x < 0) x = 0;
        else if (x > POLE_COLS - 1) x = POLE_COLS - 1;
    }
}