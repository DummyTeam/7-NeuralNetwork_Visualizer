#pragma once

#include "NeuralNetwork.h"

class MainWindow
{
public:
	MainWindow();
	void addSubscriber(Visualizable*);

	double getLayerVerticalOffset(int);
	sf::RenderWindow* getRenderWindow();
	void startWindow();

private:
	NeuralNetwork* nn;
	sf::RenderWindow* window;
	std::string currentStage;
	std::vector<Visualizable*> subscribers;
	sf::Thread* viewThread;

	float h;
	float l;
	float gap;
	float padding;
	float networkRatio;
	float neuronDiameter;
	float networkVerticalOffset;
	float distanceBetweenLayers;
	float networkHorizontalOffset;

	int numberOfLayers;
	int maxNeuronsInALayer;

	void drawNetwork();
};