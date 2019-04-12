#pragma once
#include "GameObject.h"


class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	virtual int getHit();
	int getType();
	bool isHittable();
private:
	int hp, type, pointVal = 0;
	bool shiny, hittable;
};

