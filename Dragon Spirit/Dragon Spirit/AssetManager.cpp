#include "pch.h"
#include "AssetManager.h"


AssetManager::AssetManager(std::shared_ptr<Game> gamePointer)
{
	gamePtr = gamePointer;
	std::vector<std::shared_ptr<GameObject>> * entitiesPointer;
	entitiesPointer = gamePtr->getEntities();
	for (int i = 0; i < 10; ++i)
	{
		for (unsigned j = 0; j < entitiesPointer[i].size(); ++j)
		{
			objects.push_back(entitiesPointer[i].at(j));
		}
	}
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
	//Else Return 0. Meaning they are equal.
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

bool AssetManager::loadLevel(int level)
{
	///Need defined level saving system.

	std::ifstream levelReader;
	
	std::string fileString;
	fileString = "file" + level;
	fileString += ".txt";
	levelReader.open(fileString.c_str());

	if (levelReader.is_open())
	{
		std::string lineData;
		while (std::getline(levelReader, lineData))
		{
			//TODO: Figure out file method.
		}
	}
	
	return false;
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

		///Stuff will go here when all subclasses of GameObject are done.
		if (dynamic_cast<PowerUp*>(objects.at(i).get()) != nullptr)
		{

		}
		/* WIP
		else if (dynamic_cast<Enemy*>(objects.at(i)) != nullptr)
		{

		}
		else if (dynamic_cast<Dragon*>(objects.at(i)) != nullptr)
		{

		}
		else if (dynamic_cast<Projectile*>(objects.at(i).get()) != nullptr)
		{

		}
		*/
		else
		{
			//Throw error if type of object is not found.
			std::cout << "Error in handling sprite updates at position " << i << " in Address "
				<< objects.at(i).get() << std::endl;
			throw "Couldn't find type of GameObject when processing sprites.";
		}
		

	}
}
