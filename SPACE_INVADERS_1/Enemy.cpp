#include "Enemy.h"

Enemy::Enemy(int x, int y, char symbol, COLORS color, int dir, int pts) : GameObject(x, y, symbol, color), direction(dir), points(pts) {}

Enemy::Enemy(const Enemy& obj) : GameObject(obj), direction(obj.direction), points(obj.points) {}

//Enemy::Enemy(Enemy&& obj) noexcept {
//
//}

Enemy::~Enemy() {}

Enemy& Enemy::operator=(const Enemy& obj) {
    if (this != &obj) { 
        GameObject::operator=(obj); //copies x, y, symbol, color
        direction = obj.direction;
        points = obj.points;
    }
    return *this;
}

int Enemy::getDirection() const {
    return direction;
}
void Enemy::setDirection(int dir) {
    if (dir >= 1) direction = dir;
}

int Enemy::getPoints() const {
    return points;
}
void Enemy::setPoints(int pts) {
    points = pts;
}

std::unique_ptr<Bullet> Enemy::tryShoot() {
    return nullptr; // Base enemies don't shoot by default
}

void Enemy::update() {
   x += direction;
   if (direction < 0) x = max(0, x);
   else x = min(POLE_COLS - 1, x);

    if (x <= 0 || x >= POLE_COLS - 1)
    {
        direction *= -1;
    }
}

void Enemy::render() const {
    draw_char(symbol, y, x, color, BLACK);
}