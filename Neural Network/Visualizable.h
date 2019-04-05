#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Visualizable
{
public:
	virtual void draw(sf::RenderWindow*) = 0;
};