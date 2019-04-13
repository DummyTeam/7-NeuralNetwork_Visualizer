#pragma once
#include "Visualizable.h"

class Graph : public Visualizable
{
public:
	Graph(double initialX, double initialY);
	void draw(sf::RenderWindow*);

private:
	sf::Vertex xAxis[2];
	sf::Vertex yAxis[2];

};
