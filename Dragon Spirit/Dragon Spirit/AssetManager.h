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
#include <iostream>
#include <algorithm>
#include <vector>

class AssetManager
{
public:
	AssetManager(std::vector<std::shared_ptr<GameObject>>, std::shared_ptr<Game>);
	~AssetManager();

	void sortSpawns(); //Quicksort SpawnData by spawnPoint value.
	bool loadLevel(); //Loads a level from file, returning true if successful.
	/*
	How exactly will a level be stored?
	We’ll have a vector of SpawnData structs for the enemies,
	but how will we store the list of checkpoints and the background?
	Will the SpawnData structs be used for effects as well (probably yes)?
	What about terrain (Cave roof, walls)?
	*/

	//Handles sprite updates depending on type and status of GameObject.
	void updateSprite();

private:
	std::vector<SpawnData> spawnData;
	std::vector<int> checkpoints;

	std::vector<std::shared_ptr<GameObject>> objects;
	std::shared_ptr<Game> gamePtr;
};

