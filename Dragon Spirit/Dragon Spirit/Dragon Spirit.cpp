/*
Dragon Spirit (1987)



*/

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Dragon Spirit");
	Game DragonGame(&window);
	
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		DragonGame.run();
	}

	return 0;
}