#include "NNGraphAdapter.h"


NNGraphAdapter::NNGraphAdapter(NeuralNetwork* nn)
{
	this->nn = nn;
	this->graph = new Graph();

	// Temporary
	this->graph->addData(32.3f);
	this->graph->addData(33.3f);
	this->graph->addData(34.6f);
	this->graph->addData(34.5f);
	this->graph->addData(35.0f);
	this->graph->addData(36.8f);
	this->graph->addData(35.0f);
	this->graph->addData(34.5f);
	this->graph->addData(34.6f);
	this->graph->addData(35.3f);
	this->graph->addData(34.3f);
	this->graph->addData(35.3f);
	this->graph->addData(34.6f);
	this->graph->addData(33.5f);
	this->graph->addData(34.0f);
	this->graph->addData(35.3f);
	this->graph->addData(36.6f);
	this->graph->addData(37.5f);
	this->graph->addData(36.0f);
	this->graph->addData(37.3f);
	this->graph->addData(38.6f);
	this->graph->addData(38.9f);
	this->graph->addData(37.0f);
	this->graph->addData(36.3f);
	this->graph->addData(35.3f);
	this->graph->addData(34.6f);
	this->graph->addData(33.6f);
	this->graph->addData(32.3f);
	this->graph->addData(33.3f);
	this->graph->addData(34.6f);
	this->graph->addData(34.5f);
	this->graph->addData(35.0f);
	this->graph->addData(36.8f);
	this->graph->addData(35.0f);
	this->graph->addData(34.5f);
	this->graph->addData(34.6f);
	this->graph->addData(35.3f);
	this->graph->addData(34.3f);
	this->graph->addData(35.3f);
	this->graph->addData(34.6f);
	this->graph->addData(33.5f);
	this->graph->addData(34.0f);
	this->graph->addData(35.3f);
	this->graph->addData(36.6f);
	this->graph->addData(37.5f);
	this->graph->addData(36.0f);
	this->graph->addData(37.3f);
	this->graph->addData(38.6f);
	this->graph->addData(38.9f);
	this->graph->addData(37.0f);
}

void NNGraphAdapter::draw(sf::RenderWindow* window) 
{
	this->graph->draw(window);
}

