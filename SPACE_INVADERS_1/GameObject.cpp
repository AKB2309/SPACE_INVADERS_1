#include "GameObject.h"

GameObject::GameObject(int x, int y, char symbol, COLORS color, bool active) : x(x), y(y), symbol(symbol), color(color), active(active)
{
}

GameObject::GameObject(const GameObject& obj) :x(obj.x), y(obj.y), symbol(obj.symbol), color(obj.color), active(obj.active)
{
}

GameObject::GameObject(GameObject&& obj) noexcept : x(std::exchange(obj.x, 0)),
y(std::exchange(obj.y, 0)),
symbol(std::exchange(obj.symbol, ' ')),
color(std::exchange(obj.color, WHITE))
{
}


GameObject& GameObject::operator=(const GameObject& obj)
{
	if (this != &obj)
	{
		x = obj.x;
		y = obj.y;
		symbol = obj.symbol;
		color = obj.color;
	}
	
	return *this;
	// TODO: insert return statement here
}

int GameObject::getX() const
{
	return x;
}

void GameObject::setX(int newX)
{
	x = newX;
}

int GameObject::getY() const
{
	return y;
}

void GameObject::setY(int newY)
{
	y = newY;
}

char GameObject::getSymbol() const
{
	return symbol;
}

void GameObject::setSymbol(char newSymbol)
{
	symbol = newSymbol;
}

COLORS GameObject::getColor() const
{
	return COLORS();
}

void GameObject::setColor(COLORS newColor)
{
	color = newColor;
}

bool GameObject::getActive() const
{
	return active;
}

void GameObject::setActive(bool active)
{
	this->active = active;
}

void GameObject::update()
{
}

void GameObject::render() const
{
	draw_char(symbol, y, x, color, BLACK);
}
