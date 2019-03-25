#include "Layer.h"

Layer::Layer()
{
	this->type = 0;
}

int Layer::getSize()
{
	return this->neurons.size();
}

void Layer::populateNeurons(int size)
{
	this->neurons.resize(size, new Neuron(14)); // TODO: Replace with id index generator. Each neuron must have a unique ID.
}

std::vector<Neuron*>& Layer::getNeurons()
{
	return (this->neurons);
}

int Layer::pushNeuron(Neuron *neuron)
{
	this->neurons.push_back(neuron);
	return neuron->getId();
}

bool Layer::deleteNeuronById(int id)
{
	for (std::vector<Neuron*>::iterator it = this->neurons.begin(); it != this->neurons.end(); ++it) {
		if ((*it)->getId() == id)
		{
			this->neurons.erase(it);
			return true;
		}
	}
	return false;
}

bool Layer::deleteNeuronsByValue(double value)
{
	bool deletedAtLeastOnce = false;
	for (std::vector<Neuron*>::iterator it = this->neurons.begin(); it != this->neurons.end(); ++it) {
		if ((*it)->getActivationValue() == value)
		{
			this->neurons.erase(it);
			deletedAtLeastOnce = true;
		}
	}
	return deletedAtLeastOnce;
}

Neuron* Layer::findNeuronById(int)
{
	for (std::vector<Neuron*>::iterator it = this->neurons.begin(); it != this->neurons.end(); ++it) {
		if ((*it)->getId() == id)
		{
			return *it;
		}
	}
	return nullptr;
}

std::vector<Neuron*>* Layer::findNeuronsByValue(double value)
{
	std::vector<Neuron*>* foundNeurons = new std::vector<Neuron*>();

	for (std::vector<Neuron*>::iterator it = this->neurons.begin(); it != this->neurons.end(); ++it) {
		if ((*it)->getActivationValue() == value)
		{
			foundNeurons->push_back(*it);
		}
	}

	return foundNeurons;
}

void Layer::assignValues(std::vector<double> const &values) {
	if (this->neurons.size() != values.size()) {
		throw "Size of the values does not match with the number of nuerons in this layer.";
	}

	int i = 0;
	for (std::vector<Neuron*>::iterator it = this->neurons.begin(); it != this->neurons.end(); ++it, i++)
	{
		// TODO: check this out! Make sure it works properly. 
		//		 find a neat way to solve this problem. 
		(*it)->setActivationValue(values[i]);
	}
}

std::vector<double> Layer::getListActivationValues() {
	std::vector<double> activationValues;
	for (std::vector<Neuron*>::iterator it = this->neurons.begin(); it != this->neurons.end(); ++it) {
		activationValues.push_back((*it)->getActivationValue());
	}

	return activationValues;
}

void Layer::calculateDelta() {
	for (std::vector<Neuron*>::iterator neuron = this->getNeurons().begin(); neuron != this->getNeurons().end(); neuron++)
	{
		//(*neuron)->calculateDelta();
	}
}

void Layer::updateWeightsAndBiases()
{
	for (std::vector<Neuron*>::iterator neuron = this->getNeurons().begin(); neuron != this->getNeurons().end(); neuron++)
	{
		(*neuron)->updateWeightAndBias();
	}
}

