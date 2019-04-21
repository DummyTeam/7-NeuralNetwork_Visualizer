#include "VisualWeight.h"
#include "VisualNeuron.h"

VisualWeight::VisualWeight(Weight* weight, VisualNeuron* from, VisualNeuron* to)
{
	this->weightPointer = weight;
	this->from = from;
	this->to = to;
}

void VisualWeight::getValueColor()
{
	sf::Color color;
	
	if (this->weightPointer->getValue() > 0)
		color = sf::Color(88, 204, 53);
	else
		color = sf::Color(217, 53, 86);

	this->weightLine[0].color = color;
	this->weightLine[1].color = color;
}

void VisualWeight::draw(sf::RenderWindow* renderWindow)
{
	this->getValueColor();
	renderWindow->draw(this->weightLine, 2, sf::Lines);
}

void VisualWeight::arrangeVisually()
{
	this->weightLine[0] = sf::Vertex(this->from->getCenterPoint());
	this->weightLine[0].color = sf::Color(127, 127, 0, 255);

	this->weightLine[1] = sf::Vertex(this->to->getCenterPoint());
	this->weightLine[1].color = sf::Color(127, 127, 0, 255);
}
