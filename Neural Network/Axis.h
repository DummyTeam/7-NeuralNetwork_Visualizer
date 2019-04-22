#pragma once
#include <SFML/Graphics.hpp>	
#include <vector>
#include "AxisNumber.h"

class Axis
{
public:
	Axis();
	void draw(sf::RenderWindow*);
	float getWidth();
	float getHeight();
	void setPosition(sf::Vector2f);

	const sf::Vector2f& getPosition() const;
	const std::vector<AxisNumber*>& getAxisNumbers();

protected:
	sf::RectangleShape* axis;
	float width;
	float height;
	std::vector<AxisNumber*> axisNumbers;
};
