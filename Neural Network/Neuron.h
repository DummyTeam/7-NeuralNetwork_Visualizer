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
	void setDelta(double);
	double getDelta();
	void setActivationValue(double);
	double squish(double value);
	void initWeightsAndBias(std::vector<Neuron*>& neurons);				// Create weights, push_back to weights vector
	void calculateActivation();
	void calculateDelta();
	void updateWeightAndBias();
	
private:
	int id;
	double bias;
	double activation;
	double delta;
	int type;
	Squishification* squishification;
	std::vector<Weight*>* weights; // Incoming
};
