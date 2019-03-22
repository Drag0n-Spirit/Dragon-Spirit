/*
Dragon Spirit (1987)



*/

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(228, 224), "Dragon Spirit");
	sf::View view(sf::FloatRect(0.f, 0.f, 228.f, 224.f));
	view.setCenter(114.f, 112.f);
	double wratio, vratio;

	//Making a test comment.

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::Resized)
			{
				wratio = (event.size.width / (float)event.size.height);
				vratio = (view.getSize().x) / (float)(view.getSize().y);
				// window ration vs view ratio
				if (wratio > vratio)
					view.setViewport(sf::FloatRect((1 - (vratio / wratio)) / 2.0, 0, (vratio / wratio), 1));
				else
					view.setViewport(sf::FloatRect(0, (1 - (wratio / vratio)) / 2.0, 1, (wratio / vratio)));
			}
		}

		window.setView(view);
		window.clear();
		window.display();
	}

	return 0;
}