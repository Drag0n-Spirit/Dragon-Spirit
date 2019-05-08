#pragma once
#include "GameObject.h"
#include "PowerTypes.h"
#include <SFML/Graphics.hpp>
#include "ObjectNumber.h"

class PowerUp : public GameObject
{
public:
	//Class inherits GameObject's constructors.

	//Needs a sprite, a position, and a powerup type.
	PowerUp(sf::Sprite, sf::Vector2f, std::shared_ptr<Game>, int);
	//Needs a sprite, the x and y of a position as well as the powerup type.
	PowerUp(sf::Sprite, float, float, std::shared_ptr<Game>, int);
	~PowerUp();

	void update();

	int getValue();

	int type = powerup;

private:
	int time;

	int value;
};

