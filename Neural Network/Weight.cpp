#include "Weight.h"
#include "Utils.h"
#include "Neuron.h"

Weight::Weight() {
	this->setValue(Utils::randomNumber());
}

Weight::Weight(double value) {
	this->setValue(value);
}

Weight::Weight(double value, Neuron* from, Neuron* to) {
	this->setValue(value);
	this->from = from;
	this->to = to;

	this->weightLine[0] = sf::Vertex(from->getCenterPoint());
	this->weightLine[0].color = sf::Color(12, 12, 12, 255);

	this->weightLine[1] = sf::Vertex(to->getCenterPoint());
	this->weightLine[1].color = sf::Color(12, 12, 12, 255);
}

void Weight::init() {

}

void Weight::setValue(double value) {

	this->getValueColor();
	this->value = value;
}

void Weight::getValueColor() {
	int r = 255;
	int g = 255;

	// Max weight limit is 2 (arbitrary)
	r = 127 - 127 * this->value / 2;
	g = 127 + 127 * this->value / 2;

	r = (r > 255) ? 255 : r;
	g = (g > 255) ? 255 : g;
	r = (r < 0) ? 0 : r;
	g = (g < 0) ? 0 : g;

	sf::Color color = sf::Color(r, g, 0, 255);
	this->weightLine[0].color = color;
	this->weightLine[1].color = color;
}


double Weight::getValue() {
	return this->value;
}

Neuron* Weight::getSourceNeuron() {
	return from;
}

Neuron* Weight::getDestinationNeuron() {
	return to;
}

void Weight::draw(sf::RenderWindow* window) {
	window->draw(this->weightLine, 2, sf::Lines);
}