#include "Game.h"
#include <iostream>
using namespace std;

void Game::checkBulletEnemyCollisions()
{
	
	for (auto& enemy: enemies)
	{
		for (auto& bullet : bullets)
		{
			Bullet& bulletCast = dynamic_cast<Bullet&>(*bullet);
			if (bulletCast.getIsPlayerBullet()) {

				if (checkCollisionGameObjects(*bullet, *enemy, 1))
				{
					bullet->setActive(false);
					enemy->setActive(false);
					score += enemy->getPoints();
					updateLevel();
					break;
				}
			}
		}
		
	}
}

void Game::checkPlayerEnemyCollisions()
{
	for (auto& enemy : enemies)
	{
		// Check if enemy reached or passed player's Y position and is close enough horizontally
		if (enemy->getY() >= player.getY() && abs(enemy->getX() - player.getX()) <= 1)
		{
			running = false; // end the game if an enemy reaches the player
			return;
		}
	}
}

void Game::checkBulletPlayerCollisions()
{
	for (auto& bullet : bullets) {
		Bullet& bulletCast = dynamic_cast<Bullet&>(*bullet);
		if (!bulletCast.getIsPlayerBullet() && checkCollisionGameObjects(*bullet, player)) {

			player.setLives(player.getLives() - 1);
			bullet->setActive(false);			
		}
	}
}

bool Game::checkCollisionGameObjects(GameObject& obj, GameObject& obj2, int range)
{
	if (abs(obj.getX() - obj2.getX()) <= range &&
		obj.getY() == obj2.getY() && obj.getActive() && obj2.getActive()) return true;
	else return false;
}


void Game::updateLevel()
{
	if (score >= 200 && score < 500) level = 2;
	else if (score >= 500) level = 3;

	if (score >= 300 && !player.getReceivedExtraLife()) player.setReceivedExtraLife(true);
}

void Game::initializeEnemies()
{
	for (int i = 0; i < 7; i++)
	{
		enemies.push_back(new EnemyType4(5 + i * 6, 2));
		enemies.push_back(new EnemyType3(5 + i * 6, 4));
		enemies.push_back(new EnemyType2(5 + i * 6, 6));
		enemies.push_back(new EnemyType1(5 + i * 6, 8));
	}
}

void Game::input()
{
	player.handleInput();
	if (GetAsyncKeyState(VK_SPACE)) {
		Bullet* newBullet = player.shoot();
		if (newBullet != nullptr) {
			bullets.push_back(newBullet);
		}
	}

	if (GetAsyncKeyState(VK_ESCAPE)) {
		running = false;
	}
}

void Game::update()
{
	player.update();

	for (auto& bullet : bullets) {
		bullet->update();
	}

	for (auto enemy : enemies) {
		enemy->setLevel(level);
		enemy->update(player.getY());

		if (auto bullet = enemy->tryShoot())
		{
			bullets.push_back(bullet.release());
		}
	}
	
	checkCollisions();	

	for (auto bullet = bullets.begin(); bullet != bullets.end(); ) {
		if (!(*bullet)->getActive()) {
			bullet = bullets.erase(bullet);
		}
		else {
			bullet++;
		}
	}

	for (auto enemy = enemies.begin(); enemy != enemies.end(); ) {
		if (!(*enemy)->getActive()) {
			enemy = enemies.erase(enemy);
		}
		else {
			enemy++;
		}
	}

	if (player.getLives() <= 0 || enemies.size() == 0) {
		running = false;
	}
}

void Game::checkCollisions()
{
	checkBulletEnemyCollisions();
	checkBulletPlayerCollisions();
	checkPlayerEnemyCollisions();
}

void Game::render()
{

	system("cls");

	status = "SCORE: " + std::to_string(score) +
		"   LIVES: " + std::to_string(player.getLives()) +
		"   LEVEL: " + std::to_string(level) +
		"   ENEMIES: " + std::to_string(enemies.size());
	draw_text(status, 0, POLE_ROWS - 1, YELLOW);


	player.render();

	for (auto bullet : bullets) {
		bullet->render();
	}

	for (auto enemy : enemies) {
		enemy->render();
	}
}

Game::Game() : running(true), player(30, 15), score(0), level(1)
{
}

Game::~Game()
{
	for (auto bullet : bullets) {
		delete bullet;
	}
	for (auto enemy : enemies) {
		delete enemy;
	}
}
void Game::run()
{
	initializeEnemies();

	while (running) {

		input();		
		update();
		checkCollisions();
		render();
		Sleep(40);
	}
	status = (enemies.size() == 0 ? "YOU WIN" : "GAME OVER");
	draw_text(status, (POLE_COLS - status.length() + 1) / 2, POLE_ROWS / 2, YELLOW);
}