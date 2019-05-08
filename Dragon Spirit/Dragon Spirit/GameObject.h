#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "ObjectNumber.h"
//#include "Game.h"

class Game;

///TODO: Comment this in depth at some point.

class GameObject
{
public:
	GameObject(sf::Sprite,float,float, std::shared_ptr<Game>);
	GameObject(sf::Sprite, sf::Vector2f, std::shared_ptr<Game>);
	~GameObject();

	virtual void update();
	virtual void collision(std::shared_ptr<GameObject>);
	virtual void changeTexture(sf::Texture);
	sf::FloatRect getHitbox();
	sf::Vector2f getPosition();

	int getHealth();

	int type = gameObject;

protected:
	std::shared_ptr<Game> gamePtr;

	int health;

	sf::Sprite object;
	
	sf::RectangleShape hitbox;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Texture texture;

};

