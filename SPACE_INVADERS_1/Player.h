#pragma once

#include "GameObject.h"
#include "Bullet.h"
#include <iostream>

const int COOLDOWN = 3;

class Player : public GameObject {

protected:
	int lives;
	int score;
	int shootCooldown = COOLDOWN;
	bool receivedExtraLife = false;

public:
	Player(int x = 0, int y = 0, char symbol = '^', COLORS color = GREEN);
	Player(const Player& obj);
	Player(Player&& obj) noexcept;
	~Player();

	Player& operator=(const Player& obj);

	void moveLeft();
	void moveRight();
	Bullet* shoot();

	void handleInput();

	int getLives() const;
	void setLives(int l);

	int getScore() const;
	void setScore(int s);

	bool getReceivedExtraLife()const;
	void setReceivedExtraLife(bool b);


	Player& operator+=(int points);  // Add points
	Player& operator-=(int points);  // Subtract points
	friend Player operator+(Player lhs, int points);
	friend Player operator-(Player lhs, int points);

	void update() override;
};


