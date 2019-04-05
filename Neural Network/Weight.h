#pragma once
#include "Visualizable.h"

class Neuron;

class Weight : public Visualizable
{
public:
	Weight();
	Weight(double value);
	Weight(double value, Neuron* from, Neuron* to);

	// Mutual init function
	void init();

	void setValue(double value);
	double getValue();

	Neuron* getSourceNeuron();

	Neuron* getDestinationNeuron();

	void draw(sf::RenderWindow*);


private:
	double value;
	Neuron* from;		// from which neuron (id)
	Neuron* to;			// to which neuron (id)

	sf::Sprite* shape;
	sf::Vertex weightLine[2];

	void getValueColor();

};
