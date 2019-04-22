#include"Axis.h"

Axis::Axis()
{
	this->height = 450.f;
	this->width = 2.f;
	int size = 5; 
	this->axis = new sf::RectangleShape(sf::Vector2f(this->height, this->width));

	/*for (size_t i = 0; i < size; i++)
	{
		AxisNumber* axisNum = new AxisNumber();

		axisNum->setPosition(
			sf::Vector2f(this->axis->getPosition().x + (this->height * i) / size, this->axis->getPosition().y)
		);

		this->axisNumbers.push_back(axisNum);
	}*/
}

void Axis::draw(sf::RenderWindow* window)
{
	window->draw(*(this->axis));

	/*for (size_t i = 0; i < this->axisNumbers.size(); i++)
	{
		this->axisNumbers.at(i)->draw(window);
	}*/
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

	/*for (size_t i = 0; i < this->axisNumbers.size(); i++)
	{
		this->axisNumbers.at(i)->setPosition(
			sf::Vector2f(this->axis->getPosition().x + (this->height * i) / this->axisNumbers.size(), this->axis->getPosition().y + 5)
		);
	}*/
}

const std::vector<AxisNumber*>& Axis::getAxisNumbers()
{
	return this->axisNumbers;
}
