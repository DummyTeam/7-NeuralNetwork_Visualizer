#pragma once
#include "Visualizable.h"
#include "NeuralNetwork.h"
#include "Graph.h"


class NNGraphAdapter : public Visualizable
{
public:
	NNGraphAdapter(NeuralNetwork*);
	void draw(sf::RenderWindow*);

private:
	Graph* graph;
	NeuralNetwork* nn;
};
