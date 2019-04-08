#pragma once
#include "GameObject.h"
class Projectile :
	public GameObject
{
public:
	//Needs a sprite, a position, and source of the projectile.
	Projectile(sf::Sprite, sf::Vector2f, std::shared_ptr<GameObject>);
	//Needs a sprite, the x and y of a position as well as object that shoots.
	Projectile(sf::Sprite, float, float, std::shared_ptr<GameObject>);
	~Projectile();

	int getDamage();

private:
	int damage = 1;
};

