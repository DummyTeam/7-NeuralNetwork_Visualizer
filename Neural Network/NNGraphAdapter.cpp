#include "NNGraphAdapter.h"


NNGraphAdapter::NNGraphAdapter(NeuralNetwork* nn)
{
	this->nn = nn;
	this->graph = new Graph(nn->getLearningMethod()->getCostHistory());
}

void NNGraphAdapter::draw(sf::RenderWindow* window) 
{
	this->graph->draw(window);
}

