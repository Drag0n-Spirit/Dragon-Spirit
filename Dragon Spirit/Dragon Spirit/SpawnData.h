#pragma once

#include "SFML/Graphics.hpp"


// A struct that is shared between Game and AssetManager to control
// what needs to be spawned where.
struct SpawnData
{
	int spawnPoint;
	sf::Vector2f spawnPos;
	int enemyType;
};