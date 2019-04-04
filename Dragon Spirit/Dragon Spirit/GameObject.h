#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

class GameObject
{
public:
	GameObject(sf::Sprite,float,float);
	GameObject(sf::Sprite, sf::Vector2f);
	~GameObject();

	virtual void update();
	virtual void collision(std::shared_ptr<GameObject>);

	sf::RectangleShape getHitbox();

private:
	sf::Sprite object;
	sf::RectangleShape hitbox;
	sf::Vector2f position;
	sf::Vector2f velocity;



};

