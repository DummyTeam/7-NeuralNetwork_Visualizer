#include"Axis.h"

Axis::Axis()
{
	this->height = 450.f;
	this->width = 2.f;
}

void Axis::draw(sf::RenderWindow* window)
{
	window->draw(*(this->axis));
}

float Axis::getWidth()
{
	return this->width;
}

float Axis::getHeight()
{
	return this->height;
}

const sf::Vector2f &Axis::getPosition() const
{
	return axis->getPosition();
}

void Axis::setPosition(sf::Vector2f pos) {
	this->axis->setPosition(pos);
}