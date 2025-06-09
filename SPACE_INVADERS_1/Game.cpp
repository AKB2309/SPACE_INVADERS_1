#include "Game.h"

void Game::checkBulletEnemyCollisions()
{
}

void Game::checkPlayerEnemyCollisions()
{
}

void Game::checkBulletPlayerCollisions()
{
	for (auto& bullet : bullets) {
		if (checkCollisionGameObjects(*bullet, player)) {

			player.setLives(player.getLives() - 1);
			bullet->setActive(false);

			
		}
	}
}

bool Game::checkCollisionGameObjects(GameObject& obj, GameObject& obj2)
{
	if (obj.getX() == obj2.getX() && obj.getY() == obj2.getY()) return true;
	else return false;
}


void Game::initializeEnemies()
{
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
	for (auto bullet = bullets.begin(); bullet != bullets.end(); ) {
		if (!(*bullet)->getActive()) {
			bullet = bullets.erase(bullet);
		}
		else {
			bullet++;
		}
	}
	if (player.getLives() <= 0) {
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
		"   LEVEL: " + std::to_string(level);
	draw_text(status, 0, POLE_ROWS - 1, YELLOW);


	player.render();

	for (auto bullet : bullets) {
		bullet->render();
	}
}

Game::Game() : running(true), player(30, 15), score(0), level(1)
{
}

Game::~Game()
{
	bullets.clear();
}

void Game::run()
{
	running = true;
	while (running) {

		input();
		checkCollisions();
		update();
		render();
		Sleep(50);
	}
	status = "GAME OVER";
	draw_text(status, (POLE_COLS - status.length() + 1) / 2, POLE_ROWS / 2, YELLOW);
}


