#pragma once

#include <SFML/Graphics.hpp>	

class Graph;

class GraphRangeStyle
{
public:
	virtual void renderGraph(Graph* graph, sf::RenderWindow* window) = 0;
};