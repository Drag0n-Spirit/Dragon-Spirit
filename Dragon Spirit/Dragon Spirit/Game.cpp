#include "pch.h"
#include "Game.h"


Game::Game(sf::RenderWindow *_window)
{
	window = _window;

}


//
Game::Game(sf::RenderWindow *_window, int _area)
{
	window = _window;

	area = _area;
}


//
Game::~Game()
{
}


//Currently a stub
void Game::run()
{

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
		gameState = gameOver;
	else
	{
		//Kill all non-dragon GameObjects

		//Set progress to nearest checkpoint

		//

	}

	return;
}

