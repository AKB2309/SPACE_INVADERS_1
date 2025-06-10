#include "Bullet.h"

Bullet::Bullet(int x, int y, int dir, COLORS color, char symbol, bool isPlayerBullet) : GameObject(x, y, symbol, color), direction(dir), isPlayerBullet(isPlayerBullet)
{
	
}

Bullet::Bullet(const Bullet& obj) : GameObject(std::move(obj)), direction(obj.direction), isPlayerBullet(obj.isPlayerBullet)
{
}

Bullet::Bullet(Bullet&& obj) noexcept : GameObject(std::move(obj)),
direction(std::exchange(obj.direction, 0)),
isPlayerBullet(std::exchange(obj.isPlayerBullet, false))
{
}

Bullet::~Bullet()
{
}

Bullet& Bullet::operator=(const Bullet& obj)
{
	if (this != &obj) {
		GameObject::operator=(obj);
		direction = obj.direction;
	}
	return *this;
}

int Bullet::getDirection() const
{
	return direction;
}

void Bullet::setDirection(int d)
{
	direction = d;
}

bool Bullet::getIsPlayerBullet() const
{
	return isPlayerBullet;
}


void Bullet::update()
{
	if (active)
		y += direction; // enemies shoot downwards



	if (y < 0 || y >= POLE_ROWS) active = false;
}

void Bullet::render() const
{
	draw_char(symbol, y, x, color, BLACK);
}
