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
	int r = 255;
	int g = 255;

	// Max weight limit is 2 (arbitrary)
	r = 127 - 127 * this->weightPointer->getValue() / 2;
	g = 127 + 127 * this->weightPointer->getValue() / 2;

	r = (r > 255) ? 255 : r;
	g = (g > 255) ? 255 : g;
	r = (r < 0) ? 0 : r;
	g = (g < 0) ? 0 : g;

	sf::Color color = sf::Color(r, g, 50, 255);
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
