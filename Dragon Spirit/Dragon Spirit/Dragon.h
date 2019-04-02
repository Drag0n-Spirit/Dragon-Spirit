#pragma once
#include <iostream>
#include "GameObject.h"


class Dragon : public GameObject
{
public:
	Dragon();
	Dragon(int _xPos, int _yPos);
	~Dragon();
	
	void update();
	void collision(std::shared_ptr<GameObject> obj);

	void powerDown();
	void powerUp();

	int getHits();
	int getFire();
	void shoot();

	void die();

private:
	int hits, heads, fire, hitTimer = 0, shotTimer = 0,
		fireType, powerups[5] = { 0, 0, 0, 0, 0 };
};

