#pragma once

#include "NeuralNetwork.h"

class Visualizer
{
public:
	Visualizer(int numberOfLayers, int maxNumberOfNeurons);
	void drawNetwork();
	void addSubscriber(Visualizable*);

	double getLayerVerticalOffset(int);
	sf::RenderWindow* getRenderWindow();

private:
	NeuralNetwork* nn;
	sf::RenderWindow* window;
	std::string currentStage;
	std::vector<Visualizable*> subscribers;

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
};