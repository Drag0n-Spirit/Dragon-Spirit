#include "pch.h"
#include "AssetManager.h"


AssetManager::AssetManager(std::vector<std::shared_ptr<GameObject>> objectList, std::shared_ptr<Game> gamePointer)
{
	objects = objectList;
	gamePtr = gamePointer;
}

AssetManager::~AssetManager()
{
}

/*
	Ok, so for quicksort to work as it is defined in the standard library
	it needs someone to define a function to compare the elements in the list 
	that it is sorting. I use compare to tell qsort how to compare Spawndata using 
	the < and > operators that I overrode in SpawnData's definition.
*/
int compare(const void* a, const void* b)
{
	//I made < and > compare spawnPosition's y value.
	if (*(SpawnData*)a < *(SpawnData*)b) return -1;
	if (*(SpawnData*)a > *(SpawnData*)b) return 1;
	//Else Return 0.
	return 0;
}

void AssetManager::sortSpawns()
{
	//Only works if not empty
	if (spawnData.size() > 0)
	{
		//I'm going to try and use std::qsort() to sort spawnData.
		//Sorts vector from beginning to end using the spawnPoint value.
		std::qsort(&spawnData, sizeof(spawnData) , sizeof(spawnData.at(0)) , compare);

	}	
}

void AssetManager::updateSprite()
{
	for (unsigned i = 0; objects.size(); ++i)
	{
		//First check to see if object needs to die.
		//Dies if its health is zero or it wanders off the bottom of the screen.
		if (objects.at(i)->getHealth() <= 0 ||
			objects.at(i)->getPosition().y > gamePtr->getScreenDim().y)
		{
			//Call deconstructor.
			delete objects.at(i).get();
			//Remove from vector.
			objects.erase(objects.begin() + i);
		}

		//if(dynamic_cast(objects.at(i)))

	}
}
