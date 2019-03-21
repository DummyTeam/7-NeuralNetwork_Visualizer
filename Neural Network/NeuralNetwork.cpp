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
		numberOfNeurons += (*it)->getNeurons()->size();
	}

	// Note: I don't know why I'm doing this line...
	//		 Maybe I can use it one day for something usefull.
	this->neuronIndex = numberOfNeurons;

	return numberOfNeurons;
}


std::vector<double> NeuralNetwork::predict(std::vector<double>& inputValues)
{
	std::vector<double> results;

	this->layers.at(0)->assignValues(inputValues);

	for (std::vector<Layer*>::iterator layerIt = this->layers.begin(); layerIt != this->layers.end(); ++layerIt)
	{
		for (std::vector<Neuron*>::iterator neuronIt = (*layerIt)->getNeurons()->begin(); neuronIt != (*layerIt)->getNeurons()->end(); ++neuronIt)
		{
			(*neuronIt)->calculateActivation();
		}
	}

	if (this->layers.size() > 1)
	{
		results = this->layers.at(this->layers.size() - 1)->getListActivationValues();
	}

	return results;
}

void NeuralNetwork::addLayer(Layer* layer) {
	this->layers.push_back(layer);
}


std::string NeuralNetwork::toString() {
	std::string view = "";

	for (std::vector<Layer*>::iterator layer = this->layers.begin(); layer != this->layers.end(); layer++)
	{
		for (std::vector<Neuron*>::iterator neuron = (*layer)->getNeurons()->begin(); neuron != (*layer)->getNeurons()->end(); neuron++)
		{
			view += ("\t" + std::to_string((*neuron)->getActivationValue()));
		}
		view += "\n-----------------------------------\n";
	}

	return view;
}

void NeuralNetwork::buildWeightConnections() {
	for (std::vector<Layer*>::iterator layer = this->layers.begin(); layer != this->layers.end(); layer++)
	{
		std::vector<Neuron*>*  something = (*layer)->getNeurons();
		std::vector<Neuron*>::iterator asda = (*layer)->getNeurons()->begin();
		std::vector<Neuron*>::iterator asd2a = (*layer)->getNeurons()->end();

		for (std::vector<Neuron*>::iterator neuron = (*layer)->getNeurons()->begin(); neuron != (*layer)->getNeurons()->end(); neuron++)
		{
			if (layer != this->layers.begin())
			{
				std::vector<Neuron*> previousLayerNeurons = *((*layer)->getNeurons());
				(*neuron)->initWeights(previousLayerNeurons);
			}
		}
	}
}