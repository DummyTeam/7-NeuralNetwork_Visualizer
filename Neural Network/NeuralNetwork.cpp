#include <SFML/System.hpp>
#include"NeuralNetwork.h"
#include"Utils.h"
#include <string>
#include <fstream>
#include<iostream>

NeuralNetwork::NeuralNetwork()
{
	this->currentStage = "Created!";
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

void NeuralNetwork::printTheResult(int i, Sample* s) {
	printf("Case: %d\tCost: %.8f\tOutput: %.8f\tNN_Output: %.8f\n",
		i,
		costFunction(s->getOutput()),
		s->getOutput().at(0),
		this->layers.at(this->layers.size() - 1)->getListActivationValues().at(0)
	);
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
	return this->learningMethod->calculateCost(expectedValues);
}

void NeuralNetwork::buildWeightsAndBiases() {
	int layerIndex = 0;
	for (std::vector<Layer*>::iterator layer = this->layers.begin(); layer != this->layers.end(); layer++) {
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

void NeuralNetwork::train(DataSet* dataSet, double learningRate, int numberOfIterations)
{
	this->currentStage = "Training...";
	this->learningMethod->train(dataSet, learningRate, numberOfIterations);
	this->currentStage = "Trained!";
}

void NeuralNetwork::test(DataSet* dataSet) {
	this->currentStage = "Testing...";

	int index = 0;
	for (std::vector<Sample*>::iterator sample = dataSet->getDataSet().begin(); sample < dataSet->getDataSet().end(); sample++) {
		// Output layer activation values after feedforward propogation
		std::vector<double> testRes = predict((*sample)->getInput());

		printf("Case: %d\tCost: %0.4f\t", index++, costFunction((*sample)->getOutput()));

		//printTheResult(++index, *sample);

		for (size_t i = 0; i < testRes.size(); i++)
		{
			printf("Output: %.4f\t", testRes[i]);
		}

		printf("\n");
	}

	this->currentStage = "Tested!";
	return;
}

const std::vector<Layer*> & NeuralNetwork::getLayers() {
	return this->layers;
}

void NeuralNetwork::setLearningMethod(LearningMethod* learningMethod) {
	this->learningMethod = learningMethod;
	this->learningMethod->setNeuralNetwork(this);
}

LearningMethod* NeuralNetwork::getLearningMethod() {
	return this->learningMethod;
}

std::string NeuralNetwork::getCurrentStage() {
	return this->currentStage;
}

void NeuralNetwork::saveNetwork(std::string filename) {
	std::ofstream file;
	file.open(filename);

	std::cout << "Saving neural network" << std::endl;
	for (auto& layer : this->layers)
	{
		if (&layer - &(this->layers.at(0)) != 0)
			for (auto& neuron : layer->getNeurons())
			{
				std::cout << std::to_string(neuron->getBias()) << std::endl;
				for (auto& weight : neuron->getInconmingWeights())
				{
					file << std::to_string(weight->getValue()) << " ";
				}
				std::cout << std::endl;
			}
	}

	file.close();
	std::cout << "Saved neural network" << std::endl;
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

NeuralNetwork::Builder* NeuralNetwork::Builder::setLearningMethod(LearningMethod* layer) {
	this->neuralNetwork->setLearningMethod(layer);
	return this;
}

NeuralNetwork* NeuralNetwork::Builder::build() {
	this->neuralNetwork->buildWeightsAndBiases();
	return this->neuralNetwork;
}
