#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void update();
	virtual void collision(GameObject);

	sf::RectangleShape getHitbox();

private:
	sf::RectangleShape hitbox;
	sf::Vector2f position;
	sf::Vector2f velocity;

};

