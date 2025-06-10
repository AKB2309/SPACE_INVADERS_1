#include "Enemy.h"

Enemy::Enemy(int x, int y, char symbol, COLORS color, int dir, int pts, int sp, int shootPr, int lev) : GameObject(x, y, symbol, color), direction(dir), points(pts), speed(sp), shootProbability(shootPr), level(lev) {}

Enemy::Enemy(const Enemy& obj) : GameObject(obj), direction(obj.direction), points(obj.points), speed(obj.speed), shootProbability(obj.shootProbability), level(obj.level) {}

Enemy::Enemy(Enemy&& obj) noexcept : GameObject(std::move(obj)),
direction(std::exchange(obj.direction, 0)),
points(std::exchange(obj.points, 0)),
speed(std::exchange(obj.speed,0)),
shootProbability(std::exchange(obj.shootProbability, 0)),
level(std::exchange(obj.level, 0))

{
}

Enemy::~Enemy() {}

Enemy& Enemy::operator=(const Enemy& obj) {
    if (this != &obj) { 
        GameObject::operator=(obj);
        direction = obj.direction;
        points = obj.points;
        speed = obj.speed;
        shootProbability = obj.shootProbability;
        level = obj.level;
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

int Enemy::getSpeed() const {
    return speed;
}
void Enemy::setSpeed(int sp) {
    speed = sp;
}

int Enemy::getShootProbability() const {
    return shootProbability;
}
void Enemy::setShootProbability(int shoots) {
    shootProbability = shoots;
}

int Enemy::getLevel() const {
    return level;
}

void Enemy::setLevel(int lev) {
    level = lev;
    switch (lev) {
    case 1:
        speed = 1;
        shootProbability = 40;
        break;
    case 2:
        speed = 2;
        shootProbability = 20;
        break;
    case 3:
        speed = 3;
        shootProbability = 10;
        break;
    }
}

std::unique_ptr<Bullet> Enemy::tryShoot() {
    if (rand() % shootProbability == 0)    {         
        int bulletSpeed = 1 + (40 / shootProbability) / 2;
        return std::make_unique<Bullet>(x, y + 1, bulletSpeed, color, '|');
    }
    return nullptr;
}

void Enemy::update(int playerY) { 
    int newX = x + direction * speed;

    if (newX < 0 || newX > POLE_COLS - 1) 
    {
        direction *= -1; // hit wall - reverse direction 
        y++;  // move down
        
        if (y > playerY) y = playerY; // don't go below player
    }
    else x = newX;    
}

void Enemy::render() const {
    draw_char(symbol, y, x, color, BLACK);
}