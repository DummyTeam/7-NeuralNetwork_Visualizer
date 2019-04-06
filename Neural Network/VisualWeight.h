#pragma once

#include "Weight.h"
#include "Neuron.h"
#include "VisualObject.h"

class VisualNeuron;

class VisualWeight : public VisualObject
{
public:
	VisualWeight(Weight*, VisualNeuron*, VisualNeuron*);
	void draw(sf::RenderWindow* window);
	void arrangeVisually();

private:
	sf::Vertex weightLine[2];
	Weight* weightPointer;
	VisualNeuron* to;
	VisualNeuron* from;

	void getValueColor();
};
