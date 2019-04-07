#include "VisualNeuron.h"

VisualNeuron::VisualNeuron(Neuron* neuron)
{
	this->neuronPointer = neuron;

	this->shapeWidth = 20.0f;
	this->shapeHeight = this->shapeWidth;

	this->shape = new sf::CircleShape(this->shapeWidth);
	this->shape->setFillColor(sf::Color::White);

	this->text = new sf::Text();
	this->font = new sf::Font();

	if (!font->loadFromFile("arial.ttf")) {
		throw "Font not found";
	}

	this->text->setFont(*font);
	this->text->setString("0.0");

	// in pixels, not points!
	this->text->setCharacterSize(12);
	this->text->setFillColor(sf::Color::Black);

	this->shape->setOutlineThickness(1);
	this->shape->setOutlineColor(sf::Color::White);
}

sf::CircleShape* VisualNeuron::getShape() {
	int r = 127;
	int g = 127;

	// Max weight limit is 2 (arbitrary)
	r = 127 - 127 * this->neuronPointer->getActivationValue() / 2;
	g = 127 + 127 * this->neuronPointer->getActivationValue() / 2;
	r = (r > 255) ? 255 : r;
	g = (g > 255) ? 255 : g;
	r = (r < 0) ? 0 : r;
	g = (g < 0) ? 0 : g;

	this->shape->setFillColor(sf::Color(r, g, 0, 255));
	return this->shape;
}

sf::Text* VisualNeuron::getText() {
	this->text->setString(std::to_string(this->neuronPointer->getActivationValue()).substr(0, 5));
	this->text->setPosition(this->getCenterPoint().x - this->text->getLocalBounds().width / 2.0, this->getCenterPoint().y - this->text->getLocalBounds().height);
	return this->text;
}

const sf::Vector2f& VisualNeuron::getInitPoint() {
	return this->shape->getPosition();
}

sf::Vector2f VisualNeuron::getCenterPoint() {
	return sf::Vector2f(this->shape->getPosition().x + this->shapeWidth, this->shape->getPosition().y + this->shapeHeight);
}

void VisualNeuron::draw(sf::RenderWindow* renderWindow) {
	renderWindow->draw(*(this->getShape()));
	renderWindow->draw(*(this->getText()));
}