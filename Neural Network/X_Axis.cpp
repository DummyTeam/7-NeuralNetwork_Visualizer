#include "X_Axis.h"

X_Axis::X_Axis()
{
	this->axis->setSize(sf::Vector2f(this->height, this->width));
	this->axis->setFillColor(sf::Color(166, 1, 180));
	this->axis->setPosition(sf::Vector2f(20.0f, 20.0f + height));
}

void X_Axis::setPosition(sf::Vector2f pos) {
	this->axis->setPosition(pos);

	for (size_t i = 0; i < this->axisNumbers.size(); i++)
	{
		this->axisNumbers.at(i)->setPosition(
			sf::Vector2f(this->axis->getPosition().x + (this->height * i) / this->axisNumbers.size(), this->axis->getPosition().y + 5)
		);
	}
}