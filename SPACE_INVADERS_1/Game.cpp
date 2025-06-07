#include "Game.h"

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
}

void Game::checkCollisions()
{
}

void Game::render()
{
	system("cls");
	player.render();

	for (auto bullet : bullets) {
		bullet->render();
	}
}

Game::Game() : running(true), player(30,15)
{
}

Game::~Game()
{
	bullets.clear();
}

void Game::run()
{
	running = true;
	ConsoleArea::LockConsoleSize(POLE_COLS, POLE_ROWS);
	while (running) {

		input();		
		update();
		render();
		Sleep(50);
	}
}


