#include "Game.h"
#include <iostream>
using namespace std;

void Game::initializeEnemies()
{
	for (int i = 0; i < 5; i++)
	{
		enemies.push_back(new EnemyType1(5 + i * 6, 2));
		enemies.push_back(new EnemyType2(5 + i * 6, 4));
		enemies.push_back(new EnemyType3(5 + i * 6, 6));
		enemies.push_back(new EnemyType4(5 + i * 6, 8));
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

	// player bullets
	for (auto& bullet : bullets) {
		bullet->update();
	}	

	for (auto enemy : enemies) {
		enemy->update();

		if (auto bullet = enemy->tryShoot()) 
		{
			bullets.push_back(bullet.release());
		}
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

	for (auto enemy : enemies) {
		enemy->render(); // calls the type of enemy
	}
}

Game::Game() : running(true), player(30,15)
{
	initializeEnemies();
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
		checkCollisions();
	}
}


