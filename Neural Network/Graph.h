#pragma once
#include "X_Axis.h"
#include "Y_Axis.h"
#include "VisualGraphData.h"
#include <vector>

class Graph : public Visualizable
{
public:
	Graph(std::vector<double>&);
	void draw(sf::RenderWindow*);
	void addData(double);

private:
	X_Axis* xAxis;
	Y_Axis* yAxis;
	std::vector<VisualGraphData*> graphData;
	std::vector<double>& costHistory;
};
