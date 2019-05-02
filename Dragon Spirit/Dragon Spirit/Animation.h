#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>


class Animation
{
public:
	Animation(std::string);
	~Animation();

	sf::Sprite update();
private:
	std::vector<sf::Texture> frames;
};

