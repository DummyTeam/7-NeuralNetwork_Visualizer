#pragma once

#include <vector>
#include "Weight.h"
#include "Squishification.h"

class Layer;

class Neuron
{
public:
	// Constructor with default ReLU squish
	Neuron(int id);

	// Constructor
	Neuron(int id, Squishification* squishification);

	// Clear enough
	int getId();

	// Returns activation value of neuron
	double getActivationValue();

	// Clear enough
	void setDelta(double);

	// Clear enough
	double getDelta();

	// Clear enough
	void setActivationValue(double);

	// Squishes sum of (weights*sourceActivation + b)
	double squish(double value);

	// Create weights, push_back to weights vector
	void initWeightsAndBias(std::vector<Neuron*> &neurons);

	// Calulates activation: a = f( weights * sourceActivation + b );
	void calculateActivation();

	// Calculate delta
	void calculateDelta(double);

	// Updates weights and biases
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
