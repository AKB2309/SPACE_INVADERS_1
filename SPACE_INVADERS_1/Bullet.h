#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{
protected:
	int direction; //1 = player bullet, -1 = enemy bullet
	bool isPlayerBullet;

public:
	Bullet(int x = 0, int y = 0, int dir = 1, COLORS color = WHITE, char symbol = '|', bool isPlayerBullet = false);
	Bullet(const Bullet& obj);
	Bullet(Bullet&& obj) noexcept;

	~Bullet();

	Bullet& operator=(const Bullet& obj);

	int getDirection()const;
	void setDirection(int d);

	bool getIsPlayerBullet()const;
	

	void update() override;
	void render() const;
};

