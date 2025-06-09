#pragma once
#include "visualization.h"
#include <iostream>
#include <windows.h>
#include <utility>

class GameObject
{
protected:
	int x, y;
	char symbol;
	bool active;
	COLORS color;

public:
	GameObject(int x = 0, int y = 0, char symbol = ' ', COLORS color = WHITE, bool active = true);
	GameObject(const GameObject& obj);
	GameObject(GameObject&& obj) noexcept;
	virtual ~GameObject() = default;

	GameObject& operator=(const GameObject& obj);

	int getX() const;
	void setX(int newX);

	int getY() const;
	void setY(int newY);

	char getSymbol() const;
	void setSymbol(char newSymbol);

	COLORS getColor() const;
	void setColor(COLORS newColor);

	virtual bool getActive() const;
	virtual void setActive(bool active);

	virtual void update();
	virtual void render() const;
};

