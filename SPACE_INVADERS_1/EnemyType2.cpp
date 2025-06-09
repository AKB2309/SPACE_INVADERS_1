#include "EnemyType2.h"

EnemyType2::EnemyType2(int x, int y) : Enemy(x, y, '#', YELLOW, 2, 20) {} // direction = 2 (faster), points = 20 

void EnemyType2::update() {
	Enemy::update();
}