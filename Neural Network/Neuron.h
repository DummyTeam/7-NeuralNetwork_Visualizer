#pragma once

#include <vector>
#include "Weight.h"
#include "Squishification.h"
#include "ReLU.h"

class Layer;

class Neuron
{
public:
	Neuron(int id);
	Neuron(int id, Squishification* squishification);

	int getId();
	double getActivationValue();
	void squish(double value);
	void initWeights(Layer& previousLayer);
	void calculateActivation(Layer& previousLayer);
	
private:
	int id;
	double bias;
	double activation;
	Squishification* squishification;
	std::vector<Weight> weights; // Incoming
};