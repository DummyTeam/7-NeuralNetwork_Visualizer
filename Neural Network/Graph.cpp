#include "Graph.h"
#include "Utils.h"

Graph::Graph(std::vector<double>& costHistory) : costHistory(costHistory)
{
	this->xAxis = new X_Axis();
	this->yAxis = new Y_Axis();
	this->costHistory = costHistory;
	this->graphData.resize(400, new VisualGraphData(0));
}

void Graph::draw(sf::RenderWindow* window)
{
	this->xAxis->draw(window);
	this->yAxis->draw(window);

	// TODO: Make this 400 value adjustable
	int size = (this->costHistory.size() < 400) ? this->costHistory.size() : 400;

	for (int i = this->costHistory.size() - 1, j = 0; i >= 0 && j < size; i--, j++)
	{
		this->graphData.at(this->graphData.size() - j - 1)->setData(this->costHistory.at(i) * 150);

		float posX = this->xAxis->getWidth() + this->xAxis->getPosition().x + size - j;
		float posY = this->xAxis->getPosition().y - this->yAxis->getWidth();

		this->graphData.at(this->graphData.size() - j - 1)->setPosition(
			posX,
			posY
		);

		this->graphData.at(this->graphData.size() - j - 1)->draw(window);

		if (j != 0)
		{
			float previousPosX = this->graphData.at(this->graphData.size() - j)->getPosition().x;
			float previousPosY = this->graphData.at(this->graphData.size() - j)->getPosition().y;
			sf::VertexArray line(sf::LinesStrip, 2);

			line[0].position = sf::Vector2f(posX, posY);
			line[0].color = sf::Color::Magenta;
			line[1].position = sf::Vector2f(previousPosX, previousPosY);
			line[1].color = sf::Color::Magenta;

			window->draw(line);
		}
	}
}

void Graph::addData(double item)
{
	this->graphData.push_back(new VisualGraphData(item));
}
