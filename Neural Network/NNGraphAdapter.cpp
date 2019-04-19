#include "NNGraphAdapter.h"


NNGraphAdapter::NNGraphAdapter(NeuralNetwork* nn)
{
	this->nn = nn;
	this->graph = new Graph();
	
}

void NNGraphAdapter::draw(sf::RenderWindow* window) 
{
	this->graph->draw(window);
}

