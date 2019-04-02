#pragma once

#include "NeuralNetwork.h"

class Visualizer
{
public:
	Visualizer(NeuralNetwork*);
	void init();
	void update();

	double getLayerVerticalOffset(int);

private:
	NeuralNetwork* nn;
	std::string currentStage;

	float h;
	float l;
	float gap;
	float padding;
	float networkRatio;
	float neuronDiameter;
	float networkVerticalOffset;
	float distanceBetweenLayers;
	float networkHorizontalOffset;

	int numberOfLayers = nn->getNumberOfLayers();
	int maxNeuronsInALayer;
};