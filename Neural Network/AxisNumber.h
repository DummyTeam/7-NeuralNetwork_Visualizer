#pragma once

#include <SFML/Graphics.hpp>	
#include <string>

class AxisNumber
{
public:
	AxisNumber();
	void setText(std::string);
	float getHeight();
	void draw(sf::RenderWindow*);
	void setPosition(sf::Vector2f);
	void setData(double data);

private:
	sf::Text* text;
	sf::Font* font;
	double data;
};