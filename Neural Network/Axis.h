#pragma once
#include "Visualizable.h"

class Axis : public Visualizable
{
public:
	Axis();
	void draw(sf::RenderWindow*);
	float getWidth();
	float getHeight();

	const sf::Vector2f& getPosition() const;

protected:
	sf::RectangleShape* axis;
	float width;
	float height;
};
