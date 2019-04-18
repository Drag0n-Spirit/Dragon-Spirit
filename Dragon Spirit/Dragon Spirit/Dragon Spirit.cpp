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

	sf::RenderWindow window(sf::VideoMode(400, 400), "Dragon Spirit");
	Game DragonGame(&window);
	
	window.setFramerateLimit(60);

	//Testing
	/*
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	*/

	sf::View view(sf::FloatRect(0.f, 0.f, 400.f, 400.f));
	view.setCenter(200.f, 200.f);
	double wratio, vratio;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
			{
				/*
				Create a resize function in game that takes an event?
				Then we could handle the view purely in game
				Otherwise we'll need to add a view to Game's constructor
				*/

				wratio = (event.size.width / (float)event.size.height);
				vratio = (view.getSize().x) / (float)(view.getSize().y);
				// window ratio vs view ratio
				if (wratio > vratio)
					view.setViewport(sf::FloatRect((1 - (vratio / wratio)) / 2.0, 0, (vratio / wratio), 1));
				else
					view.setViewport(sf::FloatRect(0, (1 - (wratio / vratio)) / 2.0, 1, (wratio / vratio)));
			}
		}

		window.setView(view);
		window.clear();
		DragonGame.run();
		//window.draw(shape);
		window.display();
	}

	return 0;
}