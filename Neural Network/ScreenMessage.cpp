#include "ScreenMessage.h"

ScreenMessage::ScreenMessage()
{
	this->message = "";

	this->text = new sf::Text();
	this->font = new sf::Font();

	if (!font->loadFromFile("arial.ttf")) {
		throw "Font not found";
	}

	this->text->setFont(*font);
	this->text->setString(this->message);

	// in pixels, not points!
	this->text->setCharacterSize(16);
	this->text->setFillColor(sf::Color::Black);

	this->text->setPosition(10.f, 10.f);
}

void ScreenMessage::setMessage(std::string message) {
	this->message = message;
}

void ScreenMessage::addMessage(std::string) {
	std::string initial = "\n";
	if (message.size() <= 0)
		initial = "";
	this->message += (initial + message);
}

void ScreenMessage::draw(sf::RenderWindow* renderWindow) {
	this->text->setString(this->message);
	renderWindow->draw(*(this->text));
}
