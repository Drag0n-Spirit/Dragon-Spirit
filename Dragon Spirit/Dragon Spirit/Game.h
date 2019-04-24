#pragma once

#include <vector>
#include <SFML\Graphics.hpp>

class GameObject;

class Game
{
public:
	Game(sf::RenderWindow *_window);
	Game(sf::RenderWindow *_window, int _area);
	~Game();
	void startScreen();
	void running();
	void bossFight();
	void animation();
	void gameOver();
	void endScreen();
	void run();
	void addScore(unsigned int scoreBonus);
	//void checkForSpawns();
	void gainLife();
	void death();
	//void spawnEnemy(SpawnData);
	//void spawnPowerup(int type = 0);
	/*
	void spawnProjectile(GameObject * source, //the object that called the function
	bool air = true, int fireType = 0);
	*/
	void checkCollisions();

	sf::Vector2u getScreenDim();
	std::vector<std::shared_ptr<GameObject>>* getEntities();

private:
	enum GameState {
		_startScreen, _running, _bossFight, _animation,
		_gameOver, _endScreen
	};
	sf::RenderWindow * window;
	sf::View view;
	sf::Event event;
	std::vector<int> checkpoints;
	bool isPaused = false;
	int gameState = _startScreen;
	int area = 0;
	int bossTime;
	int progress = 0;
	int lives = 6;
	int score = 0;
	//AssetManager assetManager;
	std::vector<GameObject *> groups[10];
	std::vector<std::shared_ptr<GameObject>> groups[10];
};

