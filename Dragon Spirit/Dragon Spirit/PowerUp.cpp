#include "pch.h"
#include "PowerUp.h"



PowerUp::PowerUp(sf::Sprite face, sf::Vector2f pos, int powType) : GameObject(face,pos)
{
	value = powType;
	time = 0;
}

PowerUp::PowerUp(sf::Sprite face, float posX, float posY, int powType) : GameObject(face, posX, posY)
{
	value = powType;
	time = 0;
}

PowerUp::~PowerUp()
{
}

void PowerUp::update()
{
	++time;

	//update position with velocity.
	position.x += velocity.x;
	position.y += velocity.y;

	hitbox.move(velocity);
	object.move(velocity);

}

int PowerUp::getValue()
{
	return value;
}
