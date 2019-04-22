#pragma once

#include "NeuralNetwork.h"

class Window
{
public:
	Window();
	Window(int screenWidth, int screenHeight);
	Window(sf::Vector2i, sf::Vector2i, std::string);

	void startWindow();
	void addAdapter(Visualizable*);
	sf::RenderWindow* getRenderWindow();

private:
	NeuralNetwork* nn;
	sf::RenderWindow* window;
	std::vector<Visualizable*> adapters;
	sf::Thread* viewThread;

	int screenWidth;
	int screenHeight;

	int screenXPos;
	int screenYPos;

	std::string windowTitle;

	void drawNetwork();
	void init();

};