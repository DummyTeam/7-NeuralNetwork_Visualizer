#pragma once

#include "NeuralNetwork.h"
#include "Visualizable.h"
#include "VisualObject.h"
#include "VisualNeuron.h"
#include "VisualWeight.h"
#include "VisualLayer.h"
#include <vector>

class NNVisualAdapter : public Visualizable
{
public:
	NNVisualAdapter(NeuralNetwork*);
	void draw(sf::RenderWindow*);
private:
	NeuralNetwork* nn;
	std::vector<VisualLayer*> visualLayers;
	std::vector<VisualWeight*> visualWeights;
	std::vector<VisualObject*> drawableObjects;

	void init();
	void arrangeVisually();
};
