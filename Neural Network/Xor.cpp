#include "Xor.h"
#include"Core.h"
#include"Utils.h"
#include"DataSet.h"
#include"ReLU.h"
#include"Sigmoid.h"

Xor::Xor() {

}

Xor::Xor(std::string dataPath, double learningRate, int numberOfIterations)
{
	this->dataPath = dataPath;
	this->learningRate = learningRate;
	this->numberOfIterations = numberOfIterations;

	this->init();
}

void Xor::init()
{
	// Initialize variables
	int numberOfInputs = 2;
	int numberOfOutputs = 1;
	int numberOfOriginalCases = 4;

	// Prepare shuffled data set
	this->dataSet = new DataSet(this->dataPath, numberOfInputs, numberOfOutputs);

	// Obsolete
	// DataSet* dataSet = new DataSet("data.data", numberOfInputs, numberOfOutputs, 4, numberOfIterations);

	// Create a neural network
	this->neuralNetwork = new NeuralNetwork();

	// Create an input layer
	Layer* inputLayer = new Layer();

	// Add created neurons to the created input layer
	inputLayer->populateNeurons(numberOfInputs, neuralNetwork);

	// Add input layer to neural network
	neuralNetwork->addLayer(inputLayer);

	// Create hidden layer
	Layer* hiddenLayer = new Layer();

	// Add created neurons to hidden layer
	hiddenLayer->populateNeurons(2, neuralNetwork);

	// Add hidden layer to neural network
	neuralNetwork->addLayer(hiddenLayer);

	// Create an output layer
	Layer* outputLayer = new Layer(); // new ReLU()

	// Add created neurons to output layer
	outputLayer->populateNeurons(numberOfOutputs, neuralNetwork);

	// Add output layer to neural network
	neuralNetwork->addLayer(outputLayer);

	// Building relationships (weights and biases) amoung neurons
	neuralNetwork->buildWeightsAndBiases();
}

void Xor::train() 
{
	// Train the network
	neuralNetwork->train(dataSet, this->learningRate, this->numberOfIterations);
}

void Xor::viewNetwork() 
{
	std::cout << neuralNetwork->toString() << std::endl;
}

