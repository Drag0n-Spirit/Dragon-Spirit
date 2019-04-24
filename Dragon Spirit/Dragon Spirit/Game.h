#pragma once

#include <vector>
#include <SFML\Graphics.hpp>
#include "PowerTypes.h"
#include "GameObject.h"
#include "PowerUp.h"
#include "Projectile.h"


class Game
{
public:
	enum objNum
	{
		dragon = 0,
		powerup,
		enemyProjectile,
		airEnemy,
		groundEnemy,
		dormant,
		dragonFire,
		dragonBomb,
		effects, 
		terrain,
		OBJNUM_SIZE
	};
	Game(sf::RenderWindow *_window);
	Game(sf::RenderWindow *_window, int _area);
	~Game();

	//Spawns a Projectile and adds it to groups vector.
	template <typename type> std::shared_ptr<type> spawnProjectile(sf::Sprite face, std::shared_ptr<GameObject> obj);
	//Spawns an Enemy and adds it to groups vector.
	//template <typename type> std::shared_ptr<type> spawnEnemy(sf::Sprite face, sf::Vector2f pos);
	//Spawns a Powerup and adds it to groups vector.
	template <typename type> std::shared_ptr<type> spawnPowerup(sf::Sprite face, sf::Vector2f pos);

	void startScreen();
	void running();
	void bossFight();
	void animation();
	void gameOver();
	void endScreen();
	void run();
	void addScore(unsigned int scoreBonus);
	void checkForSpawns();
	void gainLife();
	void death();
	//void spawnEnemy(SpawnData);
	void spawnPowerup(int type = 0);
	void spawnProjectile(GameObject * source, //the object that called the function
		bool air = true, int fireType = 0);
	void checkCollisions();

	sf::Vector2f viewsize;
	
	
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
	sf::Sprite mapbackround;
	sf::Texture maptexture;
	//AssetManager assetManager;
	std::vector<std::shared_ptr<GameObject>> groups[10];
};

