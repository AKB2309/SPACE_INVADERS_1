#include "Player.h"

Player::Player(int x = 0, int y = 0, char symbol = '^', COLORS color = GREEN)
{

}
Player::Player(const Player& obj) {}
Player::Player(Player&& obj) {}
Player::~Player() {}

Player& Player::operator=(const Player& obj) {

}
void Player::moveLeft() {
	x += -1;

}
void Player::moveRight() {
	x += +1;

}
void Player::shoot() {

}

int Player::getLives() const {
	return lives;
}
void Player::setLives(int l) {
	lives = l;
}

int Player::getScore() const {
	return score;
}
void Player::setScore(int s) {
	score = s;
}

Player& Player::operator+(){

}
Player& Player::operator-() {

}