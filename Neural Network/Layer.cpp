#include "Layer.h"

Layer::Layer()
{
	
}



int Layer::getSize()
{
	return this->neurons.size();
}

void Layer::setSize(int size)
{
	this->neurons.resize(size, new Neuron(14)); // TODO: Replace with id index generator. Each neuron must have a unique ID.
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