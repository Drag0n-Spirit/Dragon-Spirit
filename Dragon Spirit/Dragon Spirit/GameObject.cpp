#include "pch.h"
#include "GameObject.h"
#include "Game.h"


GameObject::GameObject(sf::Sprite face, float x, float y, std::shared_ptr<Game> game)
{
	//Initialize values
	object = face;
	object.setOrigin(x, y);
	position = sf::Vector2f(x, y);
	velocity = sf::Vector2f(0, 0);

	//Hitbox initially depends on sprite.
	sf::FloatRect spriteBounds = object.getGlobalBounds();
	hitbox = sf::RectangleShape();
	//Size is the same as the size of the sprite.
	hitbox.setSize(sf::Vector2f(spriteBounds.width, spriteBounds.height));
	hitbox.setOrigin(x, y);

	gamePtr = game;

	//health is defaulted to 1.
	health = 1;
}


GameObject::GameObject(sf::Sprite face, sf::Vector2f pos, std::shared_ptr<Game> game)
{
	//Initialize values
	object = face;
	object.setOrigin(pos);
	position = pos;
	velocity = sf::Vector2f(0, 0);

	//Hitbox initially depends on sprite.
	sf::FloatRect spriteBounds = object.getGlobalBounds();
	hitbox = sf::RectangleShape();
	//Size is the same as the size of the sprite.
	hitbox.setSize(sf::Vector2f(spriteBounds.width, spriteBounds.height));
	hitbox.setOrigin(pos);

	gamePtr = game;
}


GameObject::~GameObject()
{
}


void GameObject::update()
{
	//update position with velocity.
	position.x += velocity.x;
	position.y += velocity.y;

	hitbox.move(velocity);
	object.move(velocity);
}


void GameObject::collision(std::shared_ptr<GameObject> collisionObject)
{

}

sf::FloatRect GameObject::getHitbox()
{
	return hitbox.getGlobalBounds();
}

sf::Vector2f GameObject::getPosition()
{
	return position;
}


sf::FloatRect GameObject::getHitbox()
{
	return hitbox.getGlobalBounds();
}

int GameObject::getHealth()
{
	return health;
}

sf::FloatRect GameObject::getHitbox()
{
	return hitbox.getGlobalBounds();
}


sf::Vector2f GameObject::getPosition()
{
	return position;
}
