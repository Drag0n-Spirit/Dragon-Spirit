#include "pch.h"
#include "Dragon.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "Projectile.h"
#include "PowerUp.h"
#include "Enemy.h"
#include "PowerTypes.h"
#include "Game.h"


Dragon::Dragon(sf::Sprite face, float _xPos, float _yPos,
	std::shared_ptr<Game> game) : GameObject(face, _xPos, _yPos, game)
{
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
		gamePtr.get()->spawnProjectile(dynamic_cast<GameObject *>(this), true,
			fireType);
		shotTimer = 15;
	}

	// Check if a ground projectile needs to be spawned
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) 
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt)) && shotTimer == 0)
	{
		gamePtr.get()->spawnProjectile(dynamic_cast<GameObject *>(this), false);
		shotTimer = 15;
	}
	
	if (hitTimer > 0) { hitTimer--; }
	if (shotTimer > 0) { shotTimer--; }
}


/* The dragon has collided with a GameObject. Figure out which type of
   game object it is and give the right effect to the dragon based off
   of the documentation. */
void Dragon::collision(std::shared_ptr<GameObject> obj)
{
	if ((dynamic_cast<Enemy *>(obj.get()) != nullptr
		|| dynamic_cast<Projectile *>(obj.get()) != nullptr) && hitTimer == 0)
		die(); // Subtract from health and make dragon invicible for some
			   // amount of time
	else if (dynamic_cast<PowerUp *>(obj.get()) != nullptr)
		powerUp(dynamic_cast<PowerUp *>(obj.get())); // Reward the player 
											   // for running into a power up.
}


// Function to take away powerups that was given to the dragon earlier in
// the game. This method is most likely going to be called from Dragon::die().
void Dragon::powerDown()
{

}


/* This method is called from Dragon::collision(). it is called when the
   Dragon runs into a powerup. this method is suppose to give the Dragon
   it's appropriate powerup. */
void Dragon::powerUp(PowerUp * powers)
{
	switch (powers->getValue())
	{

	}
}


/* This method is called from Dragon::collision. It is called when an the
   Dragon runs into an objec that kills it. This method goes through the
   procedures of killing the Dragon and deciding whether or not to go back
   to the last checkpoint. */
void Dragon::die()
{
	powerDown(); // Powerups that are taken away when the dragon dies
				 // should now be taken away.
	if (hits == 0) // A life should be taken away from the dragon.
		gamePtr.get()->death();   // Reset to checkpoint.
	else // The dragon still has time left to get to the next checkpoint.
	{
		hits--;
		hitTimer = 30;
	}
}


// Getters
int Dragon::getHits() { return hits; }
int Dragon::getFire() { return fire; }
