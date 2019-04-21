#include "VisualNeuron.h"

VisualNeuron::VisualNeuron(Neuron* neuron)
{
	this->neuronPointer = neuron;

	this->shapeWidth = VisualNeuron::radius();
	this->shapeHeight = this->shapeWidth;

	this->shape = new sf::CircleShape(this->shapeWidth);
	this->shape->setFillColor(sf::Color(217, 53, 86));

	this->text = new sf::Text();
	this->font = new sf::Font();

	if (!font->loadFromFile("arial.ttf")) {
		throw "Font not found";
	}

	this->text->setFont(*font);
	this->text->setString("0.0");

	// in pixels, not points!
	this->text->setCharacterSize(12);
	this->text->setFillColor(sf::Color::White);

	this->shape->setOutlineThickness(3);
	this->shape->setOutlineColor(sf::Color::White);
}

sf::CircleShape* VisualNeuron::getShape() {
	if (this->neuronPointer->getActivationValue() > 0.000001)
		this->shape->setFillColor(sf::Color(88, 204, 53));
	else
		this->shape->setFillColor(sf::Color(217, 53, 86));

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