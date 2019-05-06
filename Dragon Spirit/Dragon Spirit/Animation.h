#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>

/*
	A simple class that loads a list of textures from a given directory.
	Based on how often update() is called it spits out a usable texture.
	Animation occurs because of the change in frames that it pushes.
*/

class Animation
{
public:
	//Takes a directory to load textures from.
	Animation(std::string);
	~Animation();

	sf::Sprite update();
private:
	std::vector<sf::Texture*> frames;
	//Current frame of Animation.
	unsigned int n;
};

