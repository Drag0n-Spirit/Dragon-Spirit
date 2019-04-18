#pragma once
#include "GameObject.h"


class Enemy : public GameObject
{
public:
	Enemy(sf::Sprite face, float _xPos, float _yPos, std::shared_ptr<Game> game);
	~Enemy();

	virtual int getHit();
	int getType();
	bool isHittable();
private:
	int hp, type, pointVal = 0;
	bool shiny, hittable;
};

