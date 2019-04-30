/*
Purposes:
Object loading
Load levels
Update all sprites
Update screen information.
*/
#pragma once
#include "PowerTypes.h"
#include "SpawnData.h"
#include "GameObject.h"
#include "PowerUp.h"
#include "Enemy.h"
#include "Dragon.h"
#include "Projectile.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>


class AssetManager
{
public:
	AssetManager(std::shared_ptr<Game>);
	~AssetManager();

	void sortSpawns(); //Quicksort SpawnData by spawnPoint value.

	//Takes an int that represents what level to load.
	//Loads a level from file, returning true if successful.
	bool loadLevel(int); 
	/*
	How exactly will a level be stored?
	We’ll have a vector of SpawnData structs for the enemies,
	but how will we store the list of checkpoints and the background?
	Will the SpawnData structs be used for effects as well (probably yes)?
	What about terrain (Cave roof, walls)?
	*/

	//Handles sprite updates depending on type and status of GameObject.
	void updateSprite();

	//Returns pointer to spawn data.
	std::shared_ptr<std::vector<SpawnData>> getSpawnData();

private:
	std::vector<SpawnData> entityTracker;
	std::vector<int> checkpoints;

	std::vector<std::shared_ptr<GameObject>> objects;
	std::shared_ptr<Game> gamePtr;
};

