#pragma once
#include "GameObject.h"
class Bullet
{
protected:
	int direction;
public:
	Bullet();
	Bullet(const Bullet& obj);
	Bullet(Bullet&& obj);

	~Bullet();

	GameObject& operator=(const GameObject& obj);

	int getDirection()const;
	void setDirection(int d);

	void update();
	void render() const;
};

