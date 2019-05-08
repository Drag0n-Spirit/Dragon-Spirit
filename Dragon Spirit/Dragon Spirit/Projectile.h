#pragma once
#include "GameObject.h"
#include "Dragon.h"
#include "ObjectNumber.h"


class Projectile :
	public GameObject
{
public:
	//Needs a sprite, a position, and source of the projectile.
	Projectile(sf::Sprite,std::shared_ptr<Game>, std::shared_ptr<GameObject>);
	~Projectile();

	int getDamage();

	int type = enemyProjectile;
private:
	int damage = 1;
};

