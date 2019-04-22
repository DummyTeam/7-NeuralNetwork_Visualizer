#pragma once

#include "GraphRangeStyle.h"

class FullRange : public GraphRangeStyle
{
public:
	FullRange(double yScaleFactor);
	void renderGraph(Graph* graph, sf::RenderWindow* window);
private:
	double yScaleFactor;
};
