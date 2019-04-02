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
	void fire();

private:
	int hits, heads, fire, hitTimer, fireType, powerups[] = { 0, 0, 0, 0, 0 };
};

