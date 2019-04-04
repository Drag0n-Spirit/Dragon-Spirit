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


//
void Game::startScreen()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		gameState = _animation;

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

		//

	}

	return;
}


