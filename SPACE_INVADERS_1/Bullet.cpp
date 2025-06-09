#include "Bullet.h"

Bullet::Bullet(int x, int y, int dir, COLORS color, char symbol) : GameObject(x, y, symbol, color), direction(dir)
{
	if (dir != 1 && dir != -1)
	{
		//exception
	}
}

Bullet::Bullet(const Bullet& obj) : GameObject(obj), direction(obj.direction)
{
}

//Bullet::Bullet(Bullet&& obj)
//{
//}

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


void Bullet::update()
{
	if (active)
		y -= direction;



	if (y < 0 || y >= POLE_ROWS) active = false;
}

void Bullet::render() const
{
	draw_char(symbol, y, x, color, BLACK);
}
