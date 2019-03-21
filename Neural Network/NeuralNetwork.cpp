#include"NeuralNetwork.h"
#include <string>

NeuralNetwork::NeuralNetwork()
{

}

int NeuralNetwork::getNeuronIndex()
{
	int numberOfNeurons = 0;

	for (std::vector<Layer*>::iterator it = this->layers.begin(); it != this->layers.end(); ++it)
	{
		numberOfNeurons += (*it)->getNeurons().size();
	}

	// Note: I don't know why I'm doing this line...
	//		 Maybe I can use it one day for something usefull.
	this->neuronIndex = numberOfNeurons;

	return numberOfNeurons;
}


std::vector<double>* NeuralNetwork::predict(std::vector<double>& inputValues)
{
	// TODO: to be implemented!

	for (std::vector<Layer*>::iterator layerIt = this->layers.begin(); layerIt != this->layers.end(); ++layerIt)
	{
		std::vector<Neuron*> neurons = (*layerIt)->getNeurons();

		for (std::vector<Neuron*>::iterator neuronIt = neurons.begin(); neuronIt != neurons.end(); ++neuronIt)
		{

		}
	}

	return nullptr;
}

void NeuralNetwork::initializeWeightsBiases()
{
	for (std::vector<Layer*>::iterator layerIt = this->layers.begin(); layerIt != this->layers.end(); ++layerIt)
	{
		std::vector<Neuron*> neurons = (*layerIt)->getNeurons();

		for (std::vector<Neuron*>::iterator neuronIt = neurons.begin(); neuronIt != neurons.end(); ++neuronIt)
		{
			//(*neuronIt)->initWeights(); // TODO: To be implemented!
		}
	}
}

void NeuralNetwork::addLayer(Layer* layer) {
	this->layers.push_back(layer);
}


std::string NeuralNetwork::toString() {
	std::string view = "";

	for (std::vector<Layer*>::iterator layer = this->layers.begin(); layer != this->layers.end(); layer++)
	{
		for (std::vector<Neuron*>::iterator neuron = (*layer)->getNeurons().begin(); neuron != (*layer)->getNeurons().end(); neuron++)
		{
			view += ("\t" + std::to_string((*neuron)->getActivationValue()));
		}
		view += "\n-----------------------------------\n";
	}

	return view;
}