#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <iostream>

class Player : public GameObject {
public:
	Player(int x = 0, int y = 0, char symbol = '^', COLORS color = GREEN);
	Player(const Player& obj);
	Player(Player&& obj);
	~Player();
	Player& operator=(const Player& obj);
	void moveLeft();
	void moveRight();
	void shoot();

	int getLives() const;
	void setLives(int l);

	int getScore() const;
	void setScore(int s);

	Player& operator+();
	Player& operator-();
protected:
	int lives;
	int score;
};

#endif // !PLAYER_H



