#include "LastNRange.h"
#include "Graph.h"

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

	for (int i = graph->getCostHistory().size() - 1, j = 0; i >= 0 && j < size; i--, j++)
	{
		graph->getGraphData().at(graph->getGraphData().size() - j - 1)->setData(graph->getCostHistory().at(i) * yScaleFactor);

		float posX = graph->getXAxis()->getPosition().x + ((graph->getXAxis()->getHeight() / rangeN) * size * 1.0) - ((graph->getXAxis()->getHeight() / rangeN) * j * 1.0);
		float posY = graph->getXAxis()->getPosition().y - graph->getYAxis()->getWidth();

		graph->getGraphData().at(graph->getGraphData().size() - j - 1)->setPosition(
			posX,
			posY
		);

		graph->getGraphData().at(graph->getGraphData().size() - j - 1)->draw(window);

		if (j != 0)
		{
			float previousPosX = graph->getGraphData().at(graph->getGraphData().size() - j)->getPosition().x;
			float previousPosY = graph->getGraphData().at(graph->getGraphData().size() - j)->getPosition().y;
			sf::VertexArray line(sf::LinesStrip, 2);

			line[0].position = sf::Vector2f(posX, posY);
			line[1].position = sf::Vector2f(previousPosX, previousPosY);

			line[0].color = sf::Color(217, 53, 86);
			line[1].color = sf::Color(217, 53, 86);

			window->draw(line);
		}
	}
}
