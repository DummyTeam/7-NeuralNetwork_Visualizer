#include "Graph.h"
#include "Utils.h"

Graph::Graph()
{
	this->xAxis = new X_Axis();
	this->yAxis = new Y_Axis();
}

void Graph::draw(sf::RenderWindow* window)
{
	this->xAxis->draw(window);
	this->yAxis->draw(window);

	for (int i = this->graphData.size() - 1, j = 0; i >= 0 && j < 250; i--, j++)
	{
		this->graphData.at(i)->setPosition(
			this->xAxis->getWidth() + this->xAxis->getPosition().x + i, 
			this->xAxis->getPosition().y - this->yAxis->getWidth()
		);
		this->graphData.at(i)->draw(window);
	}
}

void Graph::addData(double item)
{
	this->graphData.push_back(new GraphData(item));
}

