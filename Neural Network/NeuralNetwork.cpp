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

void NeuralNetwork::train(DataSet* dataSet) {

	std::auto_ptr<std::vector<double>> results;
	dataSet->getDataSet()->at(0).getInput();
	for (std::vector<Sample>::iterator trainingSample = dataSet->getDataSet()->begin(); trainingSample != dataSet->getDataSet()->end(); trainingSample++)
	{
		*results = this->predict((*trainingSample).at(0));
		this->backPropogate(*results, (*trainingSample).at(1));
	}
}

// This method should be in Layer.h
void NeuralNetwork::backPropogate(std::vector<double>& results, std::vector<double>& expected)
{
	Layer* outputLayer = this->layers.at(this->layers.size() - 1);

	if (results.size() != expected.size() || results.size() != (*(outputLayer->getNeurons())).size())
	{
		throw "Size of the resulting array of numbers from prediction does not match with the size of expected value array. Number of expected values should be equal to the number of output layer neurons.";
	}

	for (size_t i = 0; i < results.size(); i++)
	{
		(*(outputLayer->getNeurons())).at(i)->setDelta(2 * (results[i] - expected[i]));
	}

	for (std::vector<Layer*>::iterator layer = this->layers.end(); layer != this->layers.begin(); layer++)
	{
		(*layer)->calculateDeltaInLayer();
	}

	for (std::vector<Layer*>::iterator layer = this->layers.begin(); layer != this->layers.end(); layer++)
	{
		if (layer != this->layers.begin())
			(*layer)->updateWeightsAndBiases();
	}
}

void NeuralNetwork::buildWeightsAndBiases() {
	for (std::vector<Layer*>::iterator layer = this->layers.begin(); layer != this->layers.end(); layer++)
	{
		if (layer != this->layers.begin())
		{
			for (std::vector<Neuron*>::iterator neuron = (*layer)->getNeurons()->begin(); neuron != (*layer)->getNeurons()->end(); neuron++)
			{
				std::vector<Neuron*>* previousLayerNeurons = (*(layer - 1))->getNeurons();
				(*neuron)->initWeightsAndBias(*previousLayerNeurons);
			}
		}
	}
}