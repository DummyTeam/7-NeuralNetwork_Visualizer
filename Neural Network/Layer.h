#pragma once

#include <vector>
#include "Neuron.h"

class NeuralNetwork;

class Layer
{
public:
	Layer();
	Layer(Squishification*);

	// These constructors will populate the layer with neurons automatically.
	// Since layer does not store the number of neurons, we directly populate them
	Layer(int);
	Layer(int, Squishification*);

	// Mutual init for all constructors
	void init();

	// Clear enough
	int getSize();

	// Resizes neurons vector
	void populateNeurons(size_t size);

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
	void calculateDelta(std::vector<double> const &, bool isOutputLayer);

	// Clear enough
	void updateWeightsAndBiases(double learningRate);


	void buildWeightsAndBiases(Layer* previousLayer);


	void calculateActivations();


	void draw(sf::RenderWindow*, bool); 
	
	void arrangeVisually(int, int);

private:

	int id;

	std::vector<Neuron*> neurons;

	Squishification* squishification;

	int type; // LayerType - TODO: Find correct way to declare an enum 
			  // so that the data type of this variable can be set 
			  // LayerType and it can be visible in Layer.cpp too. 
			  // Don't forget to apply it in the constructor as well.


};