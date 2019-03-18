#include "Neuron.h"

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

void Neuron::calculateActivation(Layer& previousLayer) {
	// TODO: to be implemented!
}

void Neuron::initWeights(Layer& previousLayer) {
	// TODO: to be implemented!
}