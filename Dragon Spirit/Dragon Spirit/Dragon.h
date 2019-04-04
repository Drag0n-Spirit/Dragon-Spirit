#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"
#include "Powerup.h"

struct Power
{
	PowerTypes powerup;
	int timer;
};


class Dragon : public GameObject
{
public:
	Dragon();
	Dragon(int _xPos, int _yPos);
	~Dragon();
	
	void update();
	void collision(std::shared_ptr<GameObject> obj);

	void powerDown();
	void powerUp(Powerup * powers);

	void die();

	// Getters
	int getHits();
	int getFire();

private:
	int hits, heads, fire, hitTimer = 0, shotTimer = 0,
		fireType;

	std::vector<Power> powerups;
};
