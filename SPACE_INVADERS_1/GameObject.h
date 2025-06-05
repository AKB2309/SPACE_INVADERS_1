#pragma once
#include "visualization.h"
class GameObject
{
protected:
	int x, y;
	char symbol;
	COLORS color;

public:
	GameObject();
	GameObject(const GameObject& obj);
	GameObject(GameObject&& obj);
	virtual ~GameObject();

	GameObject& operator=(const GameObject& obj);

	int getX() const;
	void setX(int newX);

	int getY() const;
	void setY(int newY);

	char getSymbol() const;
	void setSymbol(char newSymbol);

	COLORS getColor() const;
	void setColor(COLORS newColor);

	virtual void update();
	virtual void render() const;


};

