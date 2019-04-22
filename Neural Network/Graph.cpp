#include "Graph.h"
#include "Utils.h"
#include "FullRange.h"
#include "LastNRange.h"

Graph::Graph(std::vector<double>& costHistory, GraphRangeStyle* graphRangeStyle) : costHistory(costHistory)
{
	this->xAxis = new X_Axis();
	this->yAxis = new Y_Axis();
	this->costHistory = costHistory;
	this->graphRangeStyle = graphRangeStyle;
}

void Graph::draw(sf::RenderWindow* window)
{
	this->graphRangeStyle->renderGraph(this, window);
}

void Graph::addData(double item)
{
	this->graphData.push_back(new VisualGraphData(item));
}

sf::Vector2u Graph::getSize() {
	return sf::Vector2u(
		this->xAxis->getHeight(),
		this->yAxis->getHeight()
	);
}

void Graph::setPosition(sf::Vector2f pos) {
	this->yAxis->setPosition(pos);
	this->xAxis->setPosition(sf::Vector2f(pos.x, pos.y + this->yAxis->getHeight()));
}

X_Axis* Graph::getXAxis() {
	return xAxis;
}

Y_Axis* Graph::getYAxis() {
	return yAxis;
}

std::vector<double>& Graph::getCostHistory() {
	return this->costHistory;
}

std::vector<VisualGraphData*>& Graph::getGraphData()
{
	return this->graphData;
}
