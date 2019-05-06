#pragma once

#include <iostream>
#include <vector>
#include "GameObject.h"
#include "Powerup.h"
#include "PowerTypes.h"

struct Power
{
	PowerTypes powerup;
	int timer;
};


class Dragon : public GameObject
{
public:
	Dragon(sf::Sprite face, float x, float y, std::shared_ptr<Game> game);
	~Dragon();
	
	void update();
	void collision(std::shared_ptr<GameObject> obj);

	void powerDown();
	void powerUp(PowerUp * powers);

	void die();

	// Getters
	int getHits();
	int getFire();

private:
	int hits, heads, fire, hitTimer = 0, shotTimer = 0, fireType = 0;

	//Testing
	sf::Texture textureTemp;

	std::vector<Power> powerups;
};
