#pragma once
#include <iostream>


class Dragon
{
public:
	Dragon();
	Dragon(int x, int y);
	~Dragon();

	void powerDown();
	void powerUp();

	int getHits();
	int getFire();
	void fire();

	void update();
	void collision(std::shared_ptr<GameObject> obj);

private:
	int hits, heads, fire, hitTimer, fireType, powerups[] = { 0, 0, 0, 0, 0 };
};

