#pragma once

#include"Layer.h"
#include"DataSet.h"
#include<vector>
#include<string>

class NeuralNetwork
{
public:

	// Initialization
	NeuralNetwork();

	// Kind of index generator for neurons. Not used right now.
	int getNeuronIndex();

	// Adds layer to layers vector
	void addLayer(Layer*);

	// Calculates delta values for all neurons and updates all the weights and biases
	// based on that delta values
	void backPropogate(std::vector<double> const &, std::vector<double> const &, double);

	// Takes vector of values and assigns it to input layer neurons.
	// Then calculates activations throughout the network.
	std::vector<double> predict(std::vector<double> &);

	// Takes a DataSet and runs each sample through predict function.
	// Then takes the output layer result and pass it through backPropogation function
	// with expected values in the sample.
	void train(DataSet*, double);

	// Returns a string which represent neurons in each layer with activation values 
	std::string toString();

	// Creates new Weight objects and bias values for each neuron
	void buildWeightsAndBiases();

	// Last layer activations subtracted from expected value
	double costFunction(std::vector<double> const &);

	//void setDataSet(DataSet*);
	//const DataSet& getDataSet();

private:
	int neuronIndex;
	std::vector<Layer*> layers;
	DataSet* dataSet;
};
