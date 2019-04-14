#include "GraphData.h"

GraphData::GraphData(double data)
{
	this->data = data;
	this->shape = new sf::CircleShape(1.f);
	this->shape->setFillColor(sf::Color(100, 250, 50));
}

void GraphData::setPosition(float x, float y)
{
	this->shape->setPosition(x, y - data);
}

void GraphData::draw(sf::RenderWindow* window)
{
	window->draw(*(this->shape));
}
