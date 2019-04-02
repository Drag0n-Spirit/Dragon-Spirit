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

void Game::gainLife()
{
	lives++;

	return;
}

