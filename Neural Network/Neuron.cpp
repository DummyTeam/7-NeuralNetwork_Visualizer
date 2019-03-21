#include "Neuron.h"
#include "Utils.h"
#include "Layer.h"
#include "ReLU.h"

Neuron::Neuron(int id)
{
	this->id = id;
	this->squishification = new ReLU();
	this->type = 0;
}

Neuron::Neuron(int id, Squishification* squishification)
{
	this->id = id;
	this->squishification = squishification;
	this->type = 0;
}

double Neuron::squish(double value)
{
	return this->squishification->squish(value);
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

void Neuron::initWeights(std::vector<Neuron*>& sourceNeurons)
{
	for (std::vector<Neuron*>::iterator neuron = sourceNeurons.begin(); neuron != sourceNeurons.end(); neuron++)
	{
		this->weights.push_back(new Weight(Utils::randomNumber(0.0, 100.0), *neuron, this));
	}
}

void Neuron::calculateActivation() {
	for (std::vector<Weight*>::iterator weight = this->weights.begin(); weight != this->weights.end(); weight++)
	{
		this->activation += ((*weight)->getSourceNeuron()->activation * (*weight)->getValue());
	}

	this->activation += this->bias;
	this->setActivationValue(this->squish(this->activation));
}