#include "LastNRange.h"
#include "Graph.h"
#include <iostream>

LastNRange::LastNRange(int rangeN, double yScaleFactor)
{
	this->rangeN = rangeN;
	this->yScaleFactor = yScaleFactor;
}

void LastNRange::renderGraph(Graph* graph, sf::RenderWindow* window) {
	if (graph->getGraphData().size() <= 0)
		graph->getGraphData().resize(rangeN, new VisualGraphData(0));

	graph->getXAxis()->draw(window);
	graph->getYAxis()->draw(window);

	int size = (graph->getCostHistory().size() < this->rangeN) ? graph->getCostHistory().size() : this->rangeN;

	for (int i = graph->getCostHistory().size() - 1, j = graph->getGraphData().size() - 1, z = 0; z < size, i >= 0 && j >= 0; i--, j--, z++)
	{
		graph->getGraphData().at(j)->setData(graph->getCostHistory().at(i) * yScaleFactor);

		graph->getGraphData().at(j)->setPosition(
			graph->getXAxis()->getPosition().x + ((graph->getXAxis()->getHeight() / rangeN) * size * 1.0) - ((graph->getXAxis()->getHeight() / rangeN) * z * 1.0),
			graph->getXAxis()->getPosition().y - graph->getYAxis()->getWidth()
		);

		graph->getGraphData().at(j)->draw(window);

		if (graph->getGraphData().size() - 1 != j)
		{
			sf::VertexArray line(sf::LinesStrip, 2);

			line[0].position = graph->getGraphData().at(j)->getPosition();
			line[1].position = graph->getGraphData().at(j + 1)->getPosition();

			/*std::cout
				<< graph->getGraphData().at(j)->getPosition().x
				<< "\t\t"
				<< graph->getGraphData().at(j)->getPosition().y
				<< "\t"
				<< graph->getGraphData().at(j + 1)->getPosition().x
				<< "\t"
				<< graph->getGraphData().at(j + 1)->getPosition().y
				<< std::endl;*/

			line[0].color = sf::Color(217, 53, 86);
			line[1].color = sf::Color(217, 53, 86);

			window->draw(line);
		}
	}
}
