#include "Dragon.h"
#include <iostream>
#include "GameObject.h"


Dragon::Dragon()
{
}
Dragon(int _xPos, int _yPos)
{
	position.x = _xPos;
	position.y = _yPos;
}
Dragon::~Dragon()
{
}


// Update the players position based off of keyboard input. Also check if
// the player has tried to fire a bullet.
void Dragon::update()
{
	double movementSpeed = 1;

	// Track the keyboard to see what the dragon should do.
	//Up and down movement.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			velocity.y = movementSpeed / sqrt(2) * -1;
		else
			velocity.y = movementSpeed * -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			velocity.y = movementSpeed / sqrt(2);
		else
			velocity.y = movementSpeed;
	}

	//Left and right movement.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			velocity.x = movementSpeed / sqrt(2) * -1;
		else
			velocity.x = movementSpeed * -1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			velocity.x = movementSpeed / sqrt(2);
		else
			velocity.x = movementSpeed;
	}

	// Check if an air projectile needs to be spawned.
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) 
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) && shotTimer == 0)
	{
		spawnProjectile(*this);
		shotTimer = 15;
	}

	// Check if a ground projectile needs to be spawned
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) 
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && shotTimer == 0)
	{
		spawnProjectile(*this, false);
		shotTimer = 15;
	}


	if (shotTimer > 0)
		shotTimer--;
	if (hitTimer > 0)
		hitTimer--;
}


/* The dragon has collided with a GameObject. Figure out which type of
   game object it is and give the right effect to the dragon based off
   of the documentation. */
void Dragon::collision(std::shared_ptr<GameObject> obj)
{
	if ((dynamic_cast<Enemy *>(obj) != nullptr 
		|| dynamic_cast<Projectile *>(obj) != nullptr) && hitTimer == 0)
	{ // Subtract from health and make dragon invicible for some
	  // amount of time
		die();
	}
	else if (dynamic_cast<PowerUps *>(obj) != nullptr)
	{ // Reward the player for running into a power up.

	}

}


void Dragon::powerDown()
{

}
void Dragon::powerUp()
{

}

int Dragon::getHits()
{

}
int Dragon::getFire()
{

}
void Dragon::shoot()
{

}

void Dragon::die()
{
	if (hits == 0)
		death();
	else
	{
		hits--;
		hitTimer = 30;
	}
}
