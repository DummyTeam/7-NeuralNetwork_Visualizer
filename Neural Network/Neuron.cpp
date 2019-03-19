#include "Neuron.h"
#include "Utils.h"
#include "Layer.h"

Neuron::Neuron(int id)
{
	this->id = id;
	this->squishification = new ReLU();
}

Neuron::Neuron(int id, Squishification* squishification)
{
	this->id = id;
	this->squishification = squishification;
}


void Neuron::squish(double value)
{
	this->squishification->squish(value);
}

int Neuron::getId()
{
	return this->id;
}

double Neuron::getActivationValue()
{
	return this->activation;
}

void Neuron::setActivationValue(double activation) {
	this->activation = activation;
}

void Neuron::calculateActivation(Layer& previousLayer) {
	// TODO: to be implemented!
}

// Creating weights and assingning random numbers for each
void Neuron::initWeights(Layer& previousLayer) 
{
	for (std::vector<Neuron*>::iterator neuron = previousLayer.getNeurons().begin();
		neuron != previousLayer.getNeurons().end();
		neuron++)
	{
		this->weights.push_back(new Weight(Utils::randomNumber(0.0, 100.0), (*neuron)->getId(), this->getId()));
	}
}