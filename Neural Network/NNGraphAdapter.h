#pragma once
#include "Visualizable.h"
#include "NeuralNetwork.h"
#include "ScreenMessage.h"
#include "Graph.h"


class NNGraphAdapter : public Visualizable
{
public:
	NNGraphAdapter(NeuralNetwork*, GraphRangeStyle*);
	void init(sf::RenderWindow*);
	void draw();

private:
	Graph* graph;
	NeuralNetwork* nn;
	ScreenMessage* screenMessage;

	sf::RenderWindow* renderWindow;

};
