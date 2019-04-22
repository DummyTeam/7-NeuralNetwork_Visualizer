#pragma once

#include "GraphRangeStyle.h"


class LastNRange : public GraphRangeStyle
{
public:
	LastNRange(int rangeN, double yScaleFactor);
	void renderGraph(Graph* graph, sf::RenderWindow* window);
private:
	int rangeN;
	double yScaleFactor;
};
