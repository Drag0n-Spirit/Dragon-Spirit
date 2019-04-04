#pragma once
#include "GameObject.h"
#include "PowerTypes.h"
#include <SFML/Graphics.hpp>

class PowerUp : public GameObject
{
public:
	//Class inherits GameObject's constructors.

	//Needs a sprite, a position, and a powerup type.
	PowerUp(sf::Sprite, sf::Vector2f, int);
	//Needs a sprite, the x and y of a position as well as the powerup type.
	PowerUp(sf::Sprite, float, float, int);
	~PowerUp();

	void update();

	int getValue();
private:
	int time;

	int value;
};

