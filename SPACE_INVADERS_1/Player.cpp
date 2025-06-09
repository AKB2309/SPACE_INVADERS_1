#include "Player.h"

Player::Player(int x, int y, char symbol, COLORS color) : GameObject(x, y, symbol, color), lives(3), score(0) { }
Player::Player(const Player& obj) : GameObject(obj), lives(obj.lives), score(obj.score) {}
//Player::Player(Player&& obj) {}
Player::~Player() {}

Player& Player::operator=(const Player& obj) {
	return *this;
}
void Player::moveLeft() {
	x += -1;
	x = max(0, x);
}
void Player::moveRight() {
	x += +1;
	x = min(POLE_COLS - 1, x);
}
Bullet* Player::shoot() {
	if (shootCooldown <= 0) {
		shootCooldown = COOLDOWN;
		return new Bullet(x, y-1, -1, WHITE, '|', true);
	}
	else return nullptr;
}

void Player::handleInput()
{
	if (GetAsyncKeyState(VK_LEFT)) moveLeft();
	if (GetAsyncKeyState(VK_RIGHT)) moveRight();
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

bool Player::getReceivedExtraLife() const
{
	return receivedExtraLife;
}

void Player::setReceivedExtraLife(bool b)
{
	receivedExtraLife = b;
	if (b)lives++;
}


Player& Player::operator+() {
	return *this;
}
Player& Player::operator-() {
	return *this;
}

void Player::update()
{
	if (shootCooldown > 0) {
		shootCooldown--;
	}
}
