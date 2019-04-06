#pragma once
#include "Visualizable.h"

class Neuron;

class Weight
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

private:
	double value;
	Neuron* from;		// from which neuron (id)
	Neuron* to;			// to which neuron (id)

};
