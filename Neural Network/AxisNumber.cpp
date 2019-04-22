#include "AxisNumber.h"

AxisNumber::AxisNumber()
{
	this->text = new sf::Text();
	this->font = new sf::Font();
	this->data = 100;

	if (!font->loadFromFile("arial.ttf")) {
		throw "Font not found";
	}

	this->text->setFont(*font);
	this->text->setString(std::to_string(data));

	// in pixels, not points!
	this->text->setCharacterSize(12);
	this->text->setFillColor(sf::Color::Black);
}

void AxisNumber::setText(std::string text)
{
	this->text->setString(text);
}

void AxisNumber::draw(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(*(this->text));
}

void AxisNumber::setPosition(sf::Vector2f pos)
{
	this->text->setPosition(pos);
}

float AxisNumber::getHeight() {
	return this->text->getGlobalBounds().height;
}

void AxisNumber::setData(double data) {
	this->text->setString(std::to_string(data));
}