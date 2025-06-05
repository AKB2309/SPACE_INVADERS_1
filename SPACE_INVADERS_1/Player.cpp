#include "Player.h"

Player::Player() {}
Player::Player(const Player& obj) {}
Player::Player(Player&& obj) {}
Player::~Player() {}

Player& Player::operator=(const Player& obj) {

}
void Player::moveLeft() {

}
void Player::moveRight() {

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