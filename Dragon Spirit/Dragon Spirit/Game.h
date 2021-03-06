#pragma once

#include <vector>
#include <SFML\Graphics.hpp>
#include "AssetManager.h"
#include "PowerTypes.h"
#include "GameObject.h"
#include "PowerUp.h"
#include "Projectile.h"
#include <iostream>


class GameObject;

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
	void pause(bool hasFocus = true);
	void resize(sf::Event);
	void addScore(unsigned int scoreBonus);
	void checkForSpawns();
	void gainLife();
	void death();
	//void spawnEnemy(SpawnData);
	//void spawnEnemy(GameObject * source);
	void spawnPowerup(GameObject * source, int type = -1);
	void spawnProjectile(GameObject * source, //the object that called the function
		bool air = true, int fireType = 0);
	void checkCollisions();

	sf::Vector2u getScreenDim();
	std::vector<std::shared_ptr<GameObject>>* getEntities();

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

	//Testing
	sf::CircleShape shape;

	sf::Sprite screen; 
	sf::Texture screenTexture;
	sf::Sprite levelBackground;
	sf::Texture backgroundTexture;

	bool isPaused = false;
	int gameState = _startScreen;
	int area = 0;
	int bossTime;
	int progress = 0; //Tracks overall progress throughout the level, in units.
	int spawnCounter = 0;
	int lives = 6;
	int score = 0;
	sf::Sprite mapbackround;
	sf::Texture maptexture;
	AssetManager assetManager;
	std::vector<std::shared_ptr<GameObject>> groups[OBJNUM_SIZE];
	//AssetManager assetManager;
	std::vector<GameObject *> groups[10];
	std::vector<std::shared_ptr<GameObject>> groups[10];
};

