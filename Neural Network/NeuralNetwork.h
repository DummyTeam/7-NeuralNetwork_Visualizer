#pragma once

#include "Layer.h"
#include "DataSet.h"
#include "LearningMethod.h"
#include <vector>
#include <string>

class NeuralNetwork
{
public:

	// Initialization
	NeuralNetwork();

	// Clear enough
	int getNumberOfLayers();

	// Compares all layer sizes and returns maximum one
	int getMaxNumberOfNeurons();

	// Adds layer to layers vector
	void addLayer(Layer*);

	// Calculates delta values for all neurons and updates all the weights and biases
	// based on that delta values
	void backPropogate(std::vector<double> const &, std::vector<double> const &, double);

	// Takes vector of values and assigns it to input layer neurons.
	// Then calculates activations throughout the network.
	std::vector<double> predict(std::vector<double> &);

	// TODO: Update the comment
	// Takes a DataSet and runs each sample through predict function.
	// Then takes the output layer result and pass it through backPropogation function
	// with expected values in the sample.
	void train(DataSet*, double, int);

	// To predict for set of inputs
	void test(DataSet*);

	// Returns a string which represent neurons in each layer with activation values 
	std::string toString();

	// Creates new Weight objects and bias values for each neuron
	void buildWeightsAndBiases();

	// Last layer activations subtracted from expected value
	double costFunction(std::vector<double> const &);

	// Clear enough
	void setLearningMethod(LearningMethod*);

	// Clear enough
	LearningMethod* getLearningMethod();

	const std::vector<Layer*> & getLayers();

	// Redundant: Delete this line
	void printTheResult(int i, Sample* s);

	// Neural Network Builder class
	class Builder
	{
	public:
		Builder();
		Builder* addLayer(Layer*);
		Builder* setLearningMethod(LearningMethod*);
		NeuralNetwork* build();

	private:
		NeuralNetwork* neuralNetwork;
	};

private:
	std::vector<Layer*> layers;
	LearningMethod* learningMethod;
};
