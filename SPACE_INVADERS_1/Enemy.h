#pragma once
#include "GameObject.h"

class Enemy : public GameObject {
public:
	Enemy();
	Enemy(int x, int y, char symbol, COLORS color, int dir);
	Enemy(const Enemy& obj);
	//Enemy(Enemy&& obj);
	virtual ~Enemy();

	Enemy& operator=(const Enemy& obj);

	int getDirection() const;
	void setDirection(int dir);

	virtual void update();
	virtual void render() const;

protected:
	int direction;
};

