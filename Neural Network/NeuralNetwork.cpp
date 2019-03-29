#include"NeuralNetwork.h"
#include <string>
#include<iostream>
#include"Utils.h"
#include <algorithm>    // std::random_shuffle

NeuralNetwork::NeuralNetwork()
{
	this->latestNeuronIndex = 0;
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
	for (std::vector<Layer*>::iterator layer = this->layers.begin(); layer != this->layers.end(); layer++) {
		if (layer != this->layers.begin()) {
			(*layer)->buildWeightsAndBiases(*(layer - 1));
		}
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

const char* NeuralNetwork::toConstChar(){
	return this->toString().c_str();
}

void NeuralNetwork::train(DataSet* dataSet, double learningRate, size_t numberOfIterations) {

	for (size_t i = 0; i < numberOfIterations; i++) {
		Sample* s = dataSet->getRandomSample();

		this->backPropogate(
			predict(s->getInput()), // Output layer activation values after feedforward propogation
			s->getOutput(),			// Expected results
			learningRate		    // Learning rate
		);

		printf("Case: %d\tCost: %f\tInput1: %f\tInput2: %f\tOutput: %f\n",
			i,
			costFunction(s->getOutput()),
			s->getInput().at(0),
			s->getInput().at(1),
			s->getOutput().at(0));
	}
	//printf("comb00: %d\tcomb01: %d\tcomb10: %d\tcomb11: %d\n", comb00, comb01, comb10, comb11);
}

void NeuralNetwork::train(DataSet* dataSet, double learningRate) {
	int index = 0;
	for (std::vector<Sample*>::iterator sample = dataSet->getDataSet().begin(); sample < dataSet->getDataSet().end(); sample++) {
		this->backPropogate(
			predict((*sample)->getInput()),		// Output layer activation values after feedforward propogation
			(*sample)->getOutput(),				// Expected results
			learningRate						// Learning rate
		);
		printf("Case: %d\tCost: %f\tInput1: %f\tInput2: %f\tOutput: %f\n", 
			index++, 
			costFunction((*sample)->getOutput()), 
			(*sample)->getInput().at(0), 
			(*sample)->getInput().at(1), 
			(*sample)->getOutput().at(0));
	}
	//printf("comb00: %d\tcomb01: %d\tcomb10: %d\tcomb11: %d\n", comb00, comb01, comb10, comb11);
}
