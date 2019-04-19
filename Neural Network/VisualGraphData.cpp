#include "VisualGraphData.h"

VisualGraphData::VisualGraphData(double data)
{
	this->data = data;
	this->shape = new sf::CircleShape(1.f);
	this->shape->setFillColor(sf::Color(100, 250, 50));
}

void VisualGraphData::setPosition(float x, float y)
{
	this->shape->setPosition(x, y - data);
}

void VisualGraphData::draw(sf::RenderWindow* window)
{
	window->draw(*(this->shape));
}

void VisualGraphData::setData(double data) {
	this->data = data;
}
