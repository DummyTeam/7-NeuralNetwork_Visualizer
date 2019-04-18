#include "X_Axis.h"

X_Axis::X_Axis()
{
	this->axis = new sf::RectangleShape(sf::Vector2f(this->height, this->width));
	this->axis->setFillColor(sf::Color::Red);
	this->axis->setPosition(sf::Vector2f(20.0f, 20.0f + height));
}