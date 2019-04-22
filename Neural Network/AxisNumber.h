#pragma once

#include <SFML/Graphics.hpp>	
#include <string>

class AxisNumber
{
public:
	AxisNumber();
	void setText(std::string);
	void draw(sf::RenderWindow*);
	void setPosition(sf::Vector2f);

private:
	sf::Text* text;
	sf::Font* font;

};

