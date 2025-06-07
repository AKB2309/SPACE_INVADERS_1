#include "Enemy.h"

Enemy::Enemy() : GameObject(), direction(1) {}

Enemy::Enemy(int x, int y, char symbol, COLORS color, int dir) : GameObject(x, y, symbol, color), direction(dir) {}

Enemy::Enemy(const Enemy& obj) : GameObject(obj), direction(obj.direction) {}

//Enemy::Enemy(Enemy&& obj) {}

Enemy::~Enemy() {}

Enemy& Enemy::operator=(const Enemy& obj) {
    if (this != &obj) { 
        direction = obj.direction;
    }
    return *this;
}
int Enemy::getDirection() const {
    return direction;
}
void Enemy::setDirection(int dir) {
    if (dir == 1) direction = dir;
}
void Enemy::update() {
    x += direction;
}
void Enemy::render() const {
    draw_char(symbol, y, x, color, BLACK);
}
