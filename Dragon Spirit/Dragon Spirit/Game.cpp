#include "pch.h"
#include "Game.h"


Game::Game(sf::RenderWindow *_window)
{
	window = _window;

}


//Start at an area beyond the first
Game::Game(sf::RenderWindow *_window, int _area)
{
	window = _window;

	area = _area;

	//Spawn a dragon and give extra powers as appropriate
}


Game::~Game()
{
}


//Spawns a Projectile and adds it to groups vector.
template <typename type> std::shared_ptr<type> Game::spawnProjectile(sf::Sprite face, std::shared_ptr<GameObject> obj)
{
	std::shared_ptr<type> thing(nullptr);
	std::string name = typeid(type).name();

	thing = std::make_shared<type>(face, this, obj);

	for (int i = 0; i < OBJNUM_SIZE; i++)
		if (i == name)
			groups[i].push_back(thing);

	return thing;
}


/*template <typename type> std::shared_ptr<type> Game::spawnEnemy(sf::Sprite face, sf::Vector2f pos)
{
	std::shared_ptr<type> thing(nullptr);
	std::string name = typeid(type).name();

	thing = std::make_shared<type>(face, pos, this, rand() % POWERTYPES_SIZE);

	for (int i = 0; i < OBJNUM_SIZE; i++)
		if (i == name)
			groups[i].push_back(thing);

	return thing;
};*/


//Spawns a Powerup and adds it to groups vector.
template <typename type> std::shared_ptr<type> Game::spawnPowerup(sf::Sprite face, sf::Vector2f pos)
{
	std::shared_ptr<type> thing(nullptr);
	std::string name = typeid(type).name();

	thing = std::make_shared<type>(face, pos, this, rand() % POWERTYPES_SIZE);

	for (int i = 0; i < OBJNUM_SIZE; i++)
		if (i == name)
			groups[i].push_back(thing);

	return thing;
};


//Show the start screen and advance to the appropriate animation when 1 is
//pressed.
void Game::startScreen()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		gameState = _animation;

	return;
}


//
void Game::running()
{
	//Iterate through vector array, updating objects
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < groups[i].size(); j++)
		{
			groups[i].at(j)->update();
			//AssetManager needs to check the object here
		}
	}
	

	checkCollisions();

	//Check here for an active earthquake.
	//For each ground enemy, call getHit.

	//Increment progress and scroll level
	progress++;
	view.move(0.f, -1.f);

	//AssetManager checks for spawns here

	//Draw the background to the window


	//For each object, draw it to the window
	window->setView(view);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < groups[i].size(); j++)
		{
			groups[i].at(j);
			//AssetManager needs to draw the sprites to the window.
		}
	}

	if (progress == bossTime)
		gameState = _bossFight;

	return;
}


//
void Game::bossFight()
{
	//Iterate through vector array, updating objects
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < groups[i].size(); j++)
		{
			groups[i].at(j)->update();
			//AssetManager needs to check the object here
		}
	}

	checkCollisions();

	//Check here for an active earthquake.
	//For each ground enemy, call getHit.

	//Draw the background to the window


	//For each object, draw it to the window
	window->setView(view);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < groups[i].size(); j++)
		{
			groups[i].at(j);
			//AssetManager needs to draw the sprites to the window.
		}
	}

	if (groups[airEnemy].size() == 0 && groups[groundEnemy].size() == 0)
		gameState = _animation;

	return;
}


//
void Game::animation()
{
	gameState = _running;

	return;
}


//Unfinished
void Game::gameOver()
{
	//Display scores

	//Advance to startScreen

	return;
}


//Unfinished
void Game::endScreen()
{
	//Display victory screens

	//Advance to startScreen

	return;
}


//Handles pausing if game is in background, and calls functions based on gameState
void Game::run()
{
	//Pause/unpause
	if (event.type == sf::Event::LostFocus)
		isPaused = true;
	else if (event.type == sf::Event::GainedFocus)
		isPaused = false;

	//If not paused, do something based on the gameState
	if (!isPaused)
	{
		//Clear window
		window->clear();

		//Drawing of shapes is done inside these functions
		switch (gameState)
		{
		case _startScreen:
			startScreen();
			break;
		case _running:
			running();
			break;
		case _bossFight:
			bossFight();
			break;
		case _animation:
			animation();
			break;
		case _gameOver:
			gameOver();
			break;
		case _endScreen:
			endScreen();
		}

		//Display the window
		window->display();
	}

	return;
}


//Add to player's score
void Game::addScore(unsigned int scoreBonus)
{
	score += scoreBonus;

	return;
}


//Give the player a partial life
void Game::gainLife()
{
	lives++;

	return;
}


//The player died. Reset to a checkpoint, unless they have no lives left
void Game::death()
{
	lives -= 3;

	if (lives <= -3)
		gameState = _gameOver;
	else
	{
		//Kill all non-dragon GameObjects

		//Set progress to nearest checkpoint
		progress = checkpoints.at(checkpoints.size() - 1);

		//

	}

	return;
}


void Game::spawnProjectile(GameObject * source, bool air, int fireType)
{
	//Spawn the projectile

	return;
}


// Function to check collisions between game objects
void Game::checkCollisions()
{
	for (int i = 0; i < *(&groups + 1) - groups; i++)
	{
		if (i == dragon) // Dragon to other groups collision.
		{
			for (int i = 0; i < groups[dragon].size(); i++)
			{
				// dragon to powerup.
				for (int j = 0; j < groups[powerup].size(); j++)
					if (groups[dragon].at(i)->getHitbox().intersects(groups[powerup].at(j)->getHitbox()))
					{
						groups[dragon].at(i)->collision(groups[powerup].at(j));
						groups[powerup].at(j)->collision(groups[dragon].at(i));
					}

				// dragon to enemyProjectile.
				for(int j = 0; j < groups[enemyProjectile].size(); j++)
					if (groups[dragon].at(i)->getHitbox().intersects(groups[enemyProjectile].at(j)->getHitbox()))
					{
						groups[dragon].at(i)->collision(groups[enemyProjectile].at(j));
						groups[enemyProjectile].at(j)->collision(groups[dragon].at(i));
					}

				// dragon to airEnemy.
				for(int j = 0; j < groups[airEnemy].size(); j++)
					if (groups[dragon].at(i)->getHitbox().intersects(groups[airEnemy].at(j)->getHitbox()))
					{
						groups[dragon].at(i)->collision(groups[airEnemy].at(j));
						groups[airEnemy].at(j)->collision(groups[dragon].at(i));
					}
			}
		}

		if (i == dragonFire) // Dragon fire to other groups collision.
		{
			for (int i = 0; i < groups[dragonFire].size(); i++)
			{
				// dragon fire to airEnemy.
				for(int j = 0; j < groups[airEnemy].size(); j++)
					if (groups[dragonFire].at(i)->getHitbox().intersects(groups[airEnemy].at(j)->getHitbox()))
					{
						groups[dragonFire].at(i)->collision(groups[airEnemy].at(j));
						groups[airEnemy].at(j)->collision(groups[dragonFire].at(i));
					}
			}
		}

		if (i == dragonBomb) // Dragon bomb to other groups collision.
		{
			for (int i = 0; i < groups[dragonBomb].size(); i++)
			{
				// dragon bomb to groundEnemy.
				for (int j = 0; j < groups[groundEnemy].size(); j++)
					if (groups[dragonBomb].at(i)->getHitbox().intersects(groups[groundEnemy].at(j)->getHitbox()))
					{
						groups[dragonBomb].at(i)->collision(groups[groundEnemy].at(j));
						groups[groundEnemy].at(j)->collision(groups[dragonBomb].at(i));
					}
			}
		}
	}
}