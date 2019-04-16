#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
//#include "Game.h"

class Game;

class GameObject
{
public:
	GameObject(sf::Sprite,float,float, std::shared_ptr<Game>);
	GameObject(sf::Sprite, sf::Vector2f, std::shared_ptr<Game>);
	~GameObject();

	virtual void update();
	virtual void collision(std::shared_ptr<GameObject>);

	sf::FloatRect getHitbox();

protected:
	std::shared_ptr<Game> gamePtr;

	sf::Sprite object;
	sf::RectangleShape hitbox;
	sf::Vector2f position;
	sf::Vector2f velocity;



};

