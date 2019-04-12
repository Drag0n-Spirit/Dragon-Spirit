#include "pch.h"
#include "AssetManager.h"


AssetManager::AssetManager()
{
}


AssetManager::~AssetManager()
{
}

void AssetManager::sortSpawns()
{
	//Only works if not empty
	if (spawnData.size() > 0)
	{
		//I'm going to try and use std::sort() to sort spawnData.
		//Sorts vector from beginning to end using the spawnPoint value.
		std::sort(spawnData.begin(), spawnData.end(), spawnData.at(0).spawnPoint);

	}	
}
