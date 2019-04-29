#include "FullRange.h"
#include "Graph.h"
#include <iostream>

FullRange::FullRange(double yScaleFactor)
{
	this->yScaleFactor = yScaleFactor;
}

void FullRange::renderGraph(Graph* graph, sf::RenderWindow* window) {
	double maxYValue = 0;

	graph->getXAxis()->draw(window);
	graph->getYAxis()->draw(window);

	if (graph->getGraphData().size() < graph->getCostHistory().size())
	{
		for (int q = 0; q < graph->getCostHistory().size() - graph->getGraphData().size(); q++)
		{
			graph->getGraphData().push_back(new VisualGraphData(
				graph->getCostHistory().at(graph->getGraphData().size() + q) * yScaleFactor
			));
		}
	}

	for (int i = 0; i < graph->getGraphData().size(); i++)
	{
		graph->getGraphData().at(i)->setPosition(
			graph->getXAxis()->getPosition().x + graph->getYAxis()->getWidth() + i * (graph->getXAxis()->getHeight() / graph->getGraphData().size() * 1.0),
			graph->getXAxis()->getPosition().y
		);

		graph->getGraphData().at(i)->draw(window);

		if (i != 0)
		{
			sf::VertexArray line(sf::LinesStrip, 2);

			line[0].position = graph->getGraphData().at(i)->getPosition();
			line[1].position = graph->getGraphData().at(i - 1)->getPosition();

			line[0].color = sf::Color(217, 53, 86);
			line[1].color = sf::Color(217, 53, 86);

			window->draw(line);
		}

		maxYValue = (graph->getGraphData().at(i)->getData() > maxYValue)
			? graph->getGraphData().at(i)->getData()
			: maxYValue;
	}
	graph->getXAxis()->setRange(graph->getGraphData().size());
	graph->getYAxis()->setRange(maxYValue / yScaleFactor * 1.0);
}
