#pragma once

#include "Drawable.h"

class Neuron;

class Weight : public Drawable
{
public:
	Weight();
	~Weight();

	Weight(double value);
	Weight(double value, Neuron* from, Neuron* to);

	void setValue(double value);
	double getValue();

	Neuron* getSourceNeuron();

	Neuron* getDestinationNeuron();

	void draw(sf::RenderWindow&);

private:
	double value;
	Neuron* from;		// from which neuron (id)
	Neuron* to;			// to which neuron (id)
	sf::Sprite* sprite;
};
