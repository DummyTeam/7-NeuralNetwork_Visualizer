#pragma once
#include <SFML/Graphics.hpp>	

class VisualGraphData
{
public:
	VisualGraphData(double data);
	void draw(sf::RenderWindow*);
	void setPosition(float x, float y);
	const sf::Vector2f& getPosition();
	void setData(double data);

private:
	sf::CircleShape* shape;
	double data;
};

