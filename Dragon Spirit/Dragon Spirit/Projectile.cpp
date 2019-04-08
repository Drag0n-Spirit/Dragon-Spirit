#include "pch.h"
#include "Projectile.h"

Projectile::Projectile(sf::Sprite face, sf::Vector2f pos, std::shared_ptr<Game> game, std::shared_ptr<GameObject> source)
	: GameObject(face,pos, game)
{
	/*if (dynamic_cast<Dragon>(source) != nullptr)
		damage = source->getFire() / 3;
	*/
}

Projectile::Projectile(sf::Sprite face, float posX, float posY,std::shared_ptr<Game> game, std::shared_ptr<GameObject> source) 
	: GameObject(face,posX,posY, game)
{
	///Uncomment when Dragon is finished
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
