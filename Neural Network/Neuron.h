#pragma once

#include <vector>
#include "Weight.h"
#include "Squishification.h"

class Layer;

class Neuron
{
public:
	Neuron(int id);
	Neuron(int id, Squishification* squishification);

	int getId();
	double getActivationValue();
	void setActivationValue(double);
	double squish(double value);
	void initWeights(std::vector<Neuron*>& neurons);				// Create weights, push_back to weights vector
	void calculateActivation();
	
private:
	int id;
	double bias;
	double activation;
	int type;
	Squishification* squishification;
	std::vector<Weight*> weights; // Incoming
};
