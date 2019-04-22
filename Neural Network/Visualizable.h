#pragma once

#include <SFML/Graphics.hpp>	

class Visualizable
{
public:
	virtual void draw() = 0;
	virtual void init(sf::RenderWindow*) = 0;
};