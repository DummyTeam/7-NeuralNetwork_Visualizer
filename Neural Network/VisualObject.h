#pragma once

#include <SFML/Graphics.hpp>

class VisualObject
{
public:
	virtual void draw(sf::RenderWindow*) = 0;
};