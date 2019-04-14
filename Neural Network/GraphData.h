#pragma once
#include "Visualizable.h"

class GraphData : public Visualizable
{
public:
	GraphData(double data);
	void draw(sf::RenderWindow*);
	void setPosition(float x, float y);

private:
	sf::CircleShape* shape;
	double data;
};

