#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>

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

