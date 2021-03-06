#include "pch.h"
#include "Game.h"
#include "Dragon.h"

#include <iostream>

Game::Game(sf::RenderWindow *_window)
{
	window = _window;

	//Initialize asset manager.
	assetManager = AssetManager(std::shared_ptr<Game>(this));


	if (!screenTexture.loadFromFile("0020.png"))
	{
		// error...
		std::cout << "Error loading texture" << std::endl;
	}
	else
	{
		screen.setTexture(screenTexture);
	}

	
	viewsize.x = 228.f;
	viewsize.y = 300.f;

	view.reset(sf::FloatRect(viewsize.x / 2, 4224.f - viewsize.y / 3, viewsize.x, viewsize.y));

	maptexture.loadFromFile("Stage_1.png");
	mapbackround.setTexture(maptexture);
	mapbackround.setTextureRect(sf::IntRect(0, 0, 384, 4424));
	mapbackround.setPosition(0, 0);

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

/*
template <typename type> std::shared_ptr<type> Game::spawnEnemy(sf::Sprite face, sf::Vector2f pos)
{
	std::shared_ptr<type> thing(nullptr);
	std::string name = typeid(type).name();

	thing = std::make_shared<type>(face, pos, this, rand() % POWERTYPES_SIZE);

	for (int i = 0; i < OBJNUM_SIZE; i++)
		if (i == name)
			groups[i].push_back(thing);

	return thing;
};
*/

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

	window->draw(screen);



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
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&  viewsize.x/2 - view.getCenter().x < 0)
		view.move(-1.f,0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && viewsize.x / 2 + view.getCenter().x < 384)
		view.move(1.f, 0.f);


	checkCollisions();

	//Check here for an active earthquake.
	//For each ground enemy, call getHit.

	//Increment progress and scroll level
	progress++;
	view.move(0.f, -0.5);

	//AssetManager checks for spawns here
	//Iterates through spawn data.
	/*
	for (unsigned i = 0; i < assetManager.getSpawnData()->size(); ++i)
	{
		//If the viewport's upper limit reaches the spawnPoint trigger in SpawnData.
		if (assetManager.getSpawnData()->at(i).spawnPoint
			== (view.getCenter().y - (getScreenDim().y / 2)))
		{
			//Resolve enemy type
			switch (assetManager.getSpawnData()->at(i).enemyType)
			{
				//convert enemy type into resolvable enemy subclass and spawn it.

			}
		}
	}
	*/


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

	//TESTING
	window->draw(shape);
	//window->draw(groups[dragon].at(0)->object);

	if (progress == bossTime)
		gameState = _bossFight;	
		
	
	
	window->draw(mapbackround);

	if (progress == bossTime)
		gameState = _bossFight;

	if (progress > (4424 - viewsize.y) / 0.5)
		gameState = _bossFight;

	std::cout << " progress:  " << progress << std::endl;
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
	area++;
	gameState = _running;

	
	

	//std::system("pause");




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
	/*
	//Pause/unpause - not working
	if (event.type == sf::Event::LostFocus)
		isPaused = true;
	else if (event.type == sf::Event::GainedFocus)
		isPaused = false;
	*/

	//Testing
	std::cout << gameState << std::endl;
	shape.setRadius(100.f);
	shape.setFillColor(sf::Color::Green);

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


//Pause the game, unless the game is paused and in the foreground, in which case
//unpause it.
void Game::pause(bool hasFocus)
{
	if (isPaused && hasFocus)
		isPaused = false;
	else
	{
		isPaused = true;
		std::cout << "Paused" << std::endl;
	}

	return;
}


//Maintains ratio between window and view
void Game::resize(sf::Event event)
{
	double wratio = (event.size.width / (float)event.size.height);
	double vratio = (view.getSize().x) / (float)(view.getSize().y);

	// window ratio vs view ratio
	if (wratio > vratio)
		view.setViewport(sf::FloatRect((1 - (vratio / wratio)) / 2.0,
			0, (vratio / wratio), 1));
	else
		view.setViewport(sf::FloatRect(0, (1 - (wratio / vratio)) / 2.0,
			1, (wratio / vratio)));

	return;
}


//Add to player's score
void Game::addScore(unsigned int scoreBonus)
{
	score += scoreBonus;

	return;
}

void Game::checkForSpawns()
{
	//Compare progress to AssetManager's vector.
	for (unsigned i = 0; i < assetManager.getSpawnData()->size(); ++i)
	{
		//If the viewport's upper limit reaches the spawnPoint trigger in SpawnData.
		if (assetManager.getSpawnData()->at(i).spawnPoint
			== (view.getCenter().y - (getScreenDim().y / 2)))
		{
			//spawn and step forwards in the vector
		}
	}


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
		
		//Set the spawnCounter to the nearest checkpoint

	}

	return;
}

sf::Vector2u Game::getScreenDim()
{
	return window->getSize();
}

std::vector<std::shared_ptr<GameObject>>* Game::getEntities()
{
	return groups;
}


//
void Game::spawnPowerup(GameObject * source, int type)
{
	//If type is -1, randomly set type.

	//Spawn powerup based on type.

	//Push it into the appropriate vector

	return;
}



void Game::spawnProjectile(GameObject * source, bool air, int fireType)
{
	//Spawn the projectile dynamically

	//Push it into the appropriate vector

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