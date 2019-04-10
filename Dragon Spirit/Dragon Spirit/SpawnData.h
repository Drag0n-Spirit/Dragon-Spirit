#pragma once
#include <SFML/Graphics.hpp>

struct SpawnData
{
	int spawnPoint;
	sf::Vector2f spawnPos;
	int enemyType;

	//Override > operator to compare y position values
	bool operator>(const SpawnData& rhs)
	{
		//I use 'this' just to be more explicit with what I am using.
		return rhs.spawnPos.y > this->spawnPos.y;
	}
	//Override < operator to compare y position values.
	bool operator<(const SpawnData& rhs)
	{
		return rhs.spawnPos.y < this->spawnPos.y;
	}

};