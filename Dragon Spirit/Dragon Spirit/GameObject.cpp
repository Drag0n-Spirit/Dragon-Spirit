#include "pch.h"
#include "GameObject.h"


GameObject::GameObject(sf::Sprite face, float x, float y)
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
}

GameObject::GameObject(sf::Sprite face, sf::Vector2f pos)
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
