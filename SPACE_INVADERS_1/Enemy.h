#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "Player.h"
#include <memory>

class Enemy : public GameObject {
protected:
	int direction;
	int points;	

public:
	Enemy(int x, int y, char symbol, COLORS color, int dir, int pts);
	Enemy(const Enemy& obj);
	//Enemy(Enemy&& obj) noexcept;
	virtual ~Enemy();

	Enemy& operator=(const Enemy& obj);

	int getDirection() const;
	void setDirection(int dir);

	int getPoints() const;
	void setPoints(int pts);

	virtual std::unique_ptr<Bullet> tryShoot();
	virtual void update() override;
	virtual void render() const override;
};

