#include "FullRange.h"
#include "Graph.h"

FullRange::FullRange(double yScaleFactor)
{
	this->yScaleFactor = yScaleFactor;
}

void FullRange::renderGraph(Graph* graph, sf::RenderWindow* window) {
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
		float posX = graph->getXAxis()->getPosition().x + graph->getYAxis()->getWidth() + i * (graph->getXAxis()->getHeight() / graph->getGraphData().size() * 1.0);
		float posY = graph->getXAxis()->getPosition().y;

		graph->getGraphData().at(i)->setPosition(
			posX,
			posY
		);

		graph->getGraphData().at(i)->draw(window);

		if (i != 0)
		{
			float previousPosX = graph->getGraphData().at(i - 1)->getPosition().x;
			float previousPosY = graph->getGraphData().at(i - 1)->getPosition().y;
			sf::VertexArray line(sf::LinesStrip, 2);

			line[0].position = sf::Vector2f(posX, posY);
			line[1].position = sf::Vector2f(previousPosX, previousPosY);

			line[0].color = sf::Color(217, 53, 86);
			line[1].color = sf::Color(217, 53, 86);

			window->draw(line);
		}
	}

	graph->getXAxis()->setRange(graph->getGraphData().size());


}
