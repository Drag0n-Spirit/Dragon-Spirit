#include "pch.h"
#include "Animation.h"


//filepath must never have a '\' at the end
Animation::Animation(std::string filepath)
{
	//We need to grab how many files there are.
	unsigned numFrames;
	std::ifstream numSpriteGrab;

	numSpriteGrab.open((filepath + ".txt").c_str());

	//Store the number of frames for later so that we don't access violate.
	//The number of frames is stored in a small txt file at beginning of directory.
	if (numSpriteGrab.is_open())
	{
		numSpriteGrab >> numFrames;
	}
	else
	{
		throw "Failed to load animation frames in constructor";
	}

	for (unsigned i = 0; i < numFrames; ++i)
	{
		//We store our textures dynamically
		sf::Texture * holder = nullptr;
		holder = new sf::Texture;

		//Initialize the textures.
		//Handle if file loading fails
		if (!holder->loadFromFile(filepath + "/" + std::to_string(i) + ".png"))
		{
			throw "Failed to load animation frames in constructor";
		}

		//Add to our vector.
		frames.push_back(holder);
	}
	n = 0;
}


Animation::~Animation()
{
	//No leaks
	for (unsigned i = 0; i < frames.size(); ++i)
	{
		delete frames.at(i);
	}
}

sf::Sprite Animation::update()
{
	if ((n + 1) > frames.size())
	{
		n = 0;
		return sf::Sprite(*frames.at(frames.size()));
	}
	//n++ is intentional, only increments after the return.
	return sf::Sprite(*frames.at(n++));
}
