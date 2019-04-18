#include "pch.h"
#include "Enemy.h"
#include "Game.h"


//Placeholder
Enemy::Enemy(sf::Sprite face, float _xPos, float _yPos,
	std::shared_ptr<Game> game) : GameObject(face, _xPos, _yPos, game)
{
}


Enemy::~Enemy()
{
}


int Enemy::getHit()
{
	if (hp <= 0) 
	{ 
		gamePtr.get()->addScore(pointVal); 
	}  

	return hp;
}


bool Enemy::isHittable() { return hittable; }
int Enemy::getType() { return type; }
