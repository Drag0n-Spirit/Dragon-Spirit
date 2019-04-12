#include "pch.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}


int Enemy::getHit()
{
	if (hp <= 0) 
	{ 
		gamePtr->addScore(pointVal); 
	}  

	return hp;
}


bool Enemy::isHittable() { return hittable; }
int Enemy::getType() { return type; }
