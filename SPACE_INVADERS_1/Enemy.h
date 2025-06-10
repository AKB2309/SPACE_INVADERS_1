#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <memory>

class Enemy : public GameObject {
protected:
	int direction; // -1 -> left, 1 -> right
	int points;	
	int speed;
	int shootProbability;
	int level;

public:
	Enemy(int x, int y, char symbol, COLORS color, int dir, int pts, int sp, int shootPr, int lev);
	Enemy(const Enemy& obj);
	//Enemy(Enemy&& obj) noexcept;
	virtual ~Enemy();

	Enemy& operator=(const Enemy& obj);

	int getDirection() const;
	void setDirection(int dir);

	int getPoints() const;
	void setPoints(int pts);

	int getSpeed() const;
	void setSpeed(int sp);

	int getShootProbability() const;
	void setShootProbability(int shoots);

	int getLevel() const;
	void setLevel(int level);

	virtual std::unique_ptr<Bullet> tryShoot();
	virtual void update(int playerY);
	virtual void render() const override;
};

