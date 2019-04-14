#pragma once
#include "X_Axis.h"
#include "Y_Axis.h"
#include "GraphData.h"
#include <vector>

class Graph : public Visualizable
{
public:
	Graph();
	void draw(sf::RenderWindow*);
	void addData(double);

private:
	X_Axis* xAxis;
	Y_Axis* yAxis;
	std::vector<GraphData*> graphData;
};
