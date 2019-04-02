#include "Dragon.h"



Dragon::Dragon()
{
}
Dragon(int _xPos, int _yPos)
{
	xPos = _xPos;
	yPos = _yPos;
}
Dragon::~Dragon()
{
}


// Update the players position based off of keyboard input. Also check if
// the player has tried to fire a bullet.
void update()
{
	double movementSpeed = 1;

	//We use basic trig to calculate diagonal movement. (hence the root 2)

	//Up and down movement.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			velocity.y = movementSpeed / sqrt(2) * -1;
		else
			velocity.y = movementSpeed * -1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			velocity.y = movementSpeed / sqrt(2);
		else
			velocity.y = movementSpeed;

	//Left and right movement.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			velocity.x = movementSpeed / sqrt(2) * -1;
		else
			velocity.x = movementSpeed * -1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			velocity.x = movementSpeed / sqrt(2);
		else
			velocity.x = movementSpeed;
}


/* The dragon has collided with a GameObject. Figure out which type of
   game object it is and give the right effect to the dragon based off
   of the documentation. */
void collision(std::shared_ptr<GameObject> obj)
{

}

void powerDown();
void powerUp();

int getHits();
int getFire();
void fire();