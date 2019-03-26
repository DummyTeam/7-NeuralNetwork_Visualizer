#include "Neuron.h"
#include "Utils.h"
#include "Layer.h"
#include "ReLU.h"
#include "Sigmoid.h"

Neuron::Neuron(int id)
{
	this->id = id;
	this->squishification = new Sigmoid();
	this->type = 0;
	this->activation = Utils::randomNumber(0, 1);
}

Neuron::Neuron(int id, Squishification* squishification)
{
	this->id = id;
	this->squishification = squishification;
	this->type = 0;
	this->activation = 1;
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

void Neuron::initWeightsAndBias(std::vector<Neuron*> &sourceNeurons)
{
	this->bias = Utils::randomNumber(0.0, 1.0);

	for (std::vector<Neuron*>::iterator neuron = sourceNeurons.begin(); neuron != sourceNeurons.end(); neuron++)
	{
		Weight* weight = new Weight(Utils::randomNumber(0.0, 1.0), *neuron, this);

		this->weights.push_back(weight);
		(*neuron)->outgoingWeights.push_back(weight);
	}
}

void Neuron::calculateActivation()
{
	this->activation = 0;

	for (std::vector<Weight*>::iterator weight = this->weights.begin(); weight != this->weights.end(); weight++) {
		if ((*weight)->getSourceNeuron() != nullptr)
			this->activation += ((*weight)->getSourceNeuron()->activation * (*weight)->getValue());
	}

	this->activation += this->bias;
	//printf("Delta: %f\tBias: %f\tActivation: %f\tSquished: %f\n", this->delta, this->bias, this->activation, this->squish(this->activation));
	this->setActivationValue(this->squish(this->activation));
}

void Neuron::updateWeightAndBias(double learningRate)
{
	for (std::vector<Weight*>::iterator weight = this->weights.begin(); weight != this->weights.end(); weight++) {
		(*weight)->setValue((*weight)->getValue() + (*weight)->getSourceNeuron()->getActivationValue() * squishification->derivative(this->activation) * learningRate * this->getDelta());
	}

	this->bias += squishification->derivative(this->activation) * learningRate * this->getDelta();
}

void Neuron::setDelta(double delta)
{
	this->delta = delta;
}

double Neuron::getDelta()
{
	return this->delta;
}

void Neuron::calculatePreviousLayerNeuronDelta() {
	this->delta = 0;
	for (std::vector<Weight*>::iterator weight = this->outgoingWeights.begin(); weight != this->outgoingWeights.end(); weight++) {
		if ((*weight)->getSourceNeuron() != nullptr && (*weight)->getDestinationNeuron() != nullptr) {
			this->delta += ((*weight)->getValue() * (*weight)->getDestinationNeuron()->getActivationValue());
		}
	}
}

void Neuron::calculateOutputNeuronDelta(double expected) {
	this->delta = (expected - this->activation);
}

std::vector<Weight*> & Neuron::getInconmingWeights() {
	return this->weights;
}

double Neuron::getBias() {
	return this->bias;
}
