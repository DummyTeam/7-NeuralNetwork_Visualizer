#pragma once
#include <SFML/Graphics.hpp>	

class Axis
{
public:
	Axis();
	void draw(sf::RenderWindow*);
	float getWidth();
	float getHeight();
	void setPosition(sf::Vector2f);

	const sf::Vector2f& getPosition() const;

protected:
	sf::RectangleShape* axis;
	float width;
	float height;
};
