#include "VisualGraphData.h"

VisualGraphData::VisualGraphData(double data)
{
	this->data = data;
	this->shape = new sf::CircleShape(1.f);
	this->shape->setFillColor(sf::Color(88, 204, 53));
}

void VisualGraphData::setPosition(float x, float y)
{
	this->shape->setPosition(x, y - data);
}

const sf::Vector2f& VisualGraphData::getPosition()
{
	return this->shape->getPosition();
}

void VisualGraphData::draw(sf::RenderWindow* window)
{
	window->draw(*(this->shape));
}

void VisualGraphData::setData(double data) {
	this->data = data;
}

double VisualGraphData::getData() {
	return this->data;
}