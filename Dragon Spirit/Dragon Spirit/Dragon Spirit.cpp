/*
Dragon Spirit (1987)



*/

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "PowerUp.h"

int main()
{
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(224, 288), "Dragon Spirit");
	Game DragonGame(&window);
	
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
			{
				//Resize DragonGame's view.
				DragonGame.resize(event);
			}
		}

		DragonGame.run();
	}

	return 0;
}