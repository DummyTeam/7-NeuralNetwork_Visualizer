#include"NeuralNetwork.h"
#include"Utils.h"
#include <string>
#include<iostream>

NeuralNetwork::NeuralNetwork()
{
	this->latestNeuronIndex = 0;
	this->willBeVisualized = false;
}

int NeuralNetwork::getNumberOfLayers() {
	return this->layers.size();
}

int NeuralNetwork::getMaxNumberOfNeurons() {
	int max = 0;
	for (std::vector<Layer*>::iterator layerIt = this->layers.begin(); layerIt != this->layers.end(); ++layerIt) {
		max = ((*layerIt)->getSize() > max) ? (*layerIt)->getSize() : max;
	}

	return max;
}

int NeuralNetwork::getNewNeuronIndex()
{
	return ++(this->latestNeuronIndex);
}

std::vector<double> NeuralNetwork::predict(std::vector<double> &inputValues)
{
	std::vector<double> results;

	this->layers.at(0)->assignValues(inputValues);

	for (std::vector<Layer*>::iterator layerIt = this->layers.begin(); layerIt != this->layers.end(); ++layerIt) {
		if (layerIt != this->layers.begin())
			(*layerIt)->calculateActivations();
	}

	if (this->layers.size() > 1) {
		results = this->layers.at(this->layers.size() - 1)->getListActivationValues();
	}

	return results;
}

void NeuralNetwork::addLayer(Layer* layer) {
	this->layers.push_back(layer);
}

void NeuralNetwork::backPropogate(std::vector<double> const &results, std::vector<double> const &expected, double learningRate) {
	if (results.size() != expected.size() || results.size() != (this->layers.at(this->layers.size() - 1)->getNeurons()).size())
		throw "Size of the resulting array of numbers from prediction does not match with the size of expected value array. Number of expected values should be equal to the number of output layer neurons.";

	for (std::vector<Layer*>::reverse_iterator layer = this->layers.rbegin(); layer != this->layers.rend(); layer++) {
		(*layer)->calculateDelta(expected, layer == this->layers.rbegin());
	}

	for (std::vector<Layer*>::iterator layer = this->layers.begin(); layer != this->layers.end(); layer++) {
		if (layer != this->layers.begin())
			(*layer)->updateWeightsAndBiases(learningRate);
	}
}

double NeuralNetwork::costFunction(std::vector<double> const & expectedValues) {
	std::vector<double> values = this->layers.at(this->layers.size() - 1)->getListActivationValues();

	if (expectedValues.size() != values.size())
		throw "Cannot calculate the cost. Number of expected outputs does not match with number of output layer neurons";

	double cost = 0;

	for (size_t i = 0; i < expectedValues.size(); i++) {
		cost += pow((values[0] - expectedValues[0]), 2);
	}

	return cost;
}

void NeuralNetwork::buildWeightsAndBiases() {
	int layerIndex = 0;
	for (std::vector<Layer*>::iterator layer = this->layers.begin(); layer != this->layers.end(); layer++) {
		//(*layer)->arrangeVisually(this->getMaxNumberOfNeurons(), layerIndex); TODO: Remove this line

		if (layer != this->layers.begin()) {
			(*layer)->buildWeightsAndBiases(*(layer - 1));
		}

		layerIndex++;
	}
}

std::string NeuralNetwork::toString() {
	std::string view = "";

	for (std::vector<Layer*>::iterator layer = this->layers.begin(); layer != this->layers.end(); layer++)
	{
		if (layer != this->layers.begin()) {
			for (std::vector<Neuron*>::iterator neuron = (*layer)->getNeurons().begin(); neuron != (*layer)->getNeurons().end(); neuron++)
			{
				for (std::vector<Weight*>::iterator weight = (*neuron)->getInconmingWeights().begin(); weight != (*neuron)->getInconmingWeights().end(); weight++)
				{
					view += ("\t " + std::to_string((*weight)->getValue()));
				}
			}
			view += "\n-----------------------------------\n";
		}

		for (std::vector<Neuron*>::iterator neuron = (*layer)->getNeurons().begin(); neuron != (*layer)->getNeurons().end(); neuron++) {
			view += ("\t  (" + std::to_string((*neuron)->getBias()) + ") " + std::to_string((*neuron)->getActivationValue()));
		}
		view += "\n-----------------------------------\n";
	}
	view += "\n";
	return view;
}

void NeuralNetwork::train(DataSet* dataSet, double learningRate, size_t numberOfIterations)
{
	for (size_t i = 0; i < numberOfIterations; i++)
	{
		Sample* s = dataSet->getRandomSample();

		this->backPropogate(
			predict(s->getInput()), // Output layer activation values after feedforward propogation
			s->getOutput(),			// Expected results
			learningRate		    // Learning rate
		);

		printf("Case: %d\tCost: %.8f\n",
			i,
			costFunction(s->getOutput()));
	}
	std::cout << this->toString() << std::endl;
}

void NeuralNetwork::test(DataSet* dataSet) {
	int index = 0;
	for (std::vector<Sample*>::iterator sample = dataSet->getDataSet().begin(); sample < dataSet->getDataSet().end(); sample++) {
		// Output layer activation values after feedforward propogation
		std::vector<double> testRes = predict((*sample)->getInput());

		printf("Case: %d\tCost: %0.4f\t", index++, costFunction((*sample)->getOutput()));

		for (size_t i = 0; i < testRes.size(); i++)
		{
			printf("Output: %.4f\t", testRes[i]);
		}

		printf("\n____________________________________________________________________________________________\n");
		std::cout << this->toString() << std::endl;
	}

	return;
}

const std::vector<Layer*> & NeuralNetwork::getLayers() {
	return this->layers;
}

bool NeuralNetwork::getWillBeVisualized() {
	return this->willBeVisualized;
}

// Builder implementation

NeuralNetwork::Builder::Builder()
{
	this->neuralNetwork = new NeuralNetwork();
}

NeuralNetwork::Builder* NeuralNetwork::Builder::addLayer(Layer* layer) {
	this->neuralNetwork->addLayer(layer);

	return this;
}

NeuralNetwork* NeuralNetwork::Builder::build() {
	this->neuralNetwork->buildWeightsAndBiases();

	return this->neuralNetwork;
}
