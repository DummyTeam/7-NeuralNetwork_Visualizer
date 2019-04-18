#include "Y_Axis.h"

Y_Axis::Y_Axis()
{
	this->axis = new sf::RectangleShape(sf::Vector2f(this->width, this->height));
	this->axis->setFillColor(sf::Color::Yellow);
	this->axis->setPosition(sf::Vector2f(20.0f, 20.0f));
}