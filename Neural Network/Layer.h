#pragma once

#include <vector>
#include "Neuron.h"

class Layer
{
public:
	Layer();

	int getSize();

	// Resizes neurons vector
	void populateNeurons(int size);

	// Get neurons vector
	std::vector<Neuron*> & getNeurons();

	// Adding new neuron to neurons vector of this layer
	int pushNeuron(Neuron*);

	// Clear enough
	bool deleteNeuronById(int);

	// Clear enough
	bool deleteNeuronsByValue(double);

	// Clear enough
	Neuron* findNeuronById(int);

	// Clear enough
	std::vector<Neuron*>* findNeuronsByValue(double);

	// Assigns given values to the layer's neurons
	void assignValues(std::vector<double> const &values);

	// Returns a list of activation values of the layer
	std::vector<double> getListActivationValues();

	// Calculates delta values
	void calculateDelta();

	// Clear enough
	void updateWeightsAndBiases();

private:

	int id;
	
	std::vector<Neuron*> neurons;
	
	int type; // LayerType - TODO: Find correct way to declare an enum 
			  // so that the data type of this variable can be set 
			  // LayerType and it can be visible in Layer.cpp too. 
			  // Don't forget to apply it in the constructor as well.
};