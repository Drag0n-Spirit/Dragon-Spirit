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

void Game::run()
{

	return;
}
