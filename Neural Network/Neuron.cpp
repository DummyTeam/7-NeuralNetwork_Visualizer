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

void Neuron::initWeightsAndBias(std::vector<Neuron*>& sourceNeurons)
{
	this->bias = Utils::randomNumber();

	for (std::vector<Neuron*>::iterator neuron = sourceNeurons.begin(); neuron != sourceNeurons.end(); neuron++)
	{
		this->weights->push_back(new Weight(Utils::randomNumber(0.0, 10.0), *neuron, this));
	}
}

void Neuron::calculateActivation()
{
	for (std::vector<Weight*>::iterator weight = this->weights->begin(); weight != this->weights->end(); weight++)
	{
		if ((*weight)->getSourceNeuron() != nullptr)
		{
			this->activation += ((*weight)->getSourceNeuron()->activation * (*weight)->getValue());
		}
	}

	this->activation += this->bias;
	this->setActivationValue(this->squish(this->activation));
}

void Neuron::updateWeightAndBias(bool isInputNeuron)
{
	for (std::vector<Weight*>::iterator weightIt = this->weights->begin(); weightIt != this->weights->end(); weightIt++)
	{
		double sqshDerivative = this->squishification->derivative((*weightIt)->getValue());
		double previousNeuron =
	}
}