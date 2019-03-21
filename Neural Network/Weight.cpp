#include "Weight.h"
#include "Utils.h"

Weight::Weight()
{
	this->setValue(Utils::randomNumber());
}

Weight::~Weight()
{
	// Not implemented
}

Weight::Weight(double value) {
	this->setValue(value);
}

Weight::Weight(double value, Neuron* from, Neuron* to) {
	this->setValue(value);
	this->from = from;
	this->to = to;
}

void Weight::setValue(double value) {
	this->value = value;
}

double Weight::getValue() {
	return this->value;
}

Neuron* Weight::getSourceNeuron() {
	return from;
}

Neuron* Weight::getDestinationNeuron() {
	return to;
}