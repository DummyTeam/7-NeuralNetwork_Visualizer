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

void Neuron::updateWeightAndBias()
{
	double learningRate = 0.01;

	for (std::vector<Weight*>::iterator weight = this->weights->begin(); weight != this->weights->end(); weight++)
	{
		(*weight)->setValue((*weight)->getValue() + this->activation * squishification->derivative(this->activation) * learningRate * this->getDelta());
	}
}

void Neuron::setDelta(double delta)
{
	this->delta = delta;
}

double Neuron::getDelta()
{
	return this->delta;
}

void Neuron::calculateDelta()
{
	for (std::vector<Weight*>::iterator weight = this->weights->begin(); weight != this->weights->end(); weight++)
	{
		if ((*weight)->getSourceNeuron() != nullptr)
		{
			(*weight)->getSourceNeuron()->delta += ((*weight)->getValue() * this->getActivationValue());
		}
	}
}