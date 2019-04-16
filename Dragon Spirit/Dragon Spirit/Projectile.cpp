#include "pch.h"
#include "Projectile.h"

Projectile::Projectile(sf::Sprite face, std::shared_ptr<Game> game, std::shared_ptr<GameObject> source)
	: GameObject(face,source->getHitbox().getPosition(), game)
{
	/*if (dynamic_cast<Dragon>(source) != nullptr)
		damage = source->getFire() / 3;
	*/
}
Projectile::~Projectile()
{
}

int Projectile::getDamage()
{
	return damage;
}
