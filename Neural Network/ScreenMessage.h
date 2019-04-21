#pragma once

#include "Visualizable.h"
#include <string>

class ScreenMessage
{
public:
	ScreenMessage();

	// Overrides all previous messages
	void setMessage(std::string);

	// Adds a new message
	void addMessage(std::string);

	// Draws messages on the screen
	void draw(sf::RenderWindow*);

private:
	std::string message;

	sf::Text* text;
	sf::Font* font;
};
