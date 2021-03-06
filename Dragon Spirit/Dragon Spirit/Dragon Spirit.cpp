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
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				//Resize DragonGame's view.
				DragonGame.resize(event);
				break;
			case sf::Event::LostFocus:
				//The game is in the background. Pause it.
				DragonGame.pause(false);
				break;
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Escape)
					DragonGame.pause();
			}
		}

		//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			//DragonGame.pause();

		DragonGame.run();
	}

	return 0;
}