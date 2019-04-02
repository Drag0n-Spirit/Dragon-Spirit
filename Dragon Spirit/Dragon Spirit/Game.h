#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <cstdlib>
#include <vector>


class Game
{
public:
	Game(sf::RenderWindow *_window);
	Game(sf::RenderWindow *_window, int _area);
	~Game();
	void run();
	void addScore(unsigned int scoreBonus);
	void checkForSpawns();
	void gainLife();
	void death();
	//void spawnEnemy(SpawnData);
	void spawnPowerup(int type = 0);
	//void spawnProjectile(GameObject * source //the object that called the function);
	void checkCollisions();
private:
	sf::RenderWindow const * window;
	sf::View view;
	bool paused = false;
	int gameState; //
	int area = 1;
	int progress = 0;
	int lives = 6;
	int score = 0;
	//AssetManager assetManager
	//vector<GameObject *> groups[10];
};

