#include"NeuralNetwork.h"

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

void NeuralNetwork::randomizeWeightsBiases()
{
	for (std::vector<Layer*>::iterator layerIt = this->layers.begin(); layerIt != this->layers.end(); ++layerIt)
	{
		std::vector<Neuron*> neurons = (*layerIt)->getNeurons();

		for (std::vector<Neuron*>::iterator neuronIt = neurons.begin(); neuronIt != neurons.end(); ++neuronIt)
		{
			(*neuronIt)->initWeights();
		}
	}
}