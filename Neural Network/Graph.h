#pragma once
#include "X_Axis.h"
#include "Y_Axis.h"
#include "VisualGraphData.h"
#include <vector>
#include "GraphRangeStyle.h"

class Graph
{
public:
	Graph(std::vector<double>&, GraphRangeStyle*);
	void draw(sf::RenderWindow*);
	void addData(double);
	sf::Vector2u getSize();
	void setPosition(sf::Vector2f);
	X_Axis* getXAxis();
	Y_Axis* getYAxis();
	std::vector<double>& getCostHistory();
	std::vector<VisualGraphData*>& getGraphData();

private:
	X_Axis* xAxis;
	Y_Axis* yAxis;
	GraphRangeStyle* graphRangeStyle;
	std::vector<double>& costHistory;
	std::vector<VisualGraphData*> graphData;
};
