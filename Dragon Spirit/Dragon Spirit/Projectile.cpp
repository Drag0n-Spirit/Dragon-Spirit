#include "pch.h"
#include "Projectile.h"

class Dragon;


Projectile::Projectile(sf::Sprite face, std::shared_ptr<Game> game, std::shared_ptr<GameObject> source)
	: GameObject(face,source->getPosition(), game)
{
	if (std::dynamic_pointer_cast<Dragon>(source) != nullptr)
		damage = std::dynamic_pointer_cast<Dragon>(source)->getFire() / 3;
}


Projectile::~Projectile()
{
}


int Projectile::getDamage() {return damage;}

