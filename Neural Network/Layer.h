#pragma once

#include <vector>
#include "Neuron.h"

class Layer
{
public:
	Layer();

	int getSize();
	void setSize(int size);
	int pushNeuron(Neuron*);
	bool deleteNeuronById(int);
	bool deleteNeuronsByValue(double);
	Neuron* findNeuronById(int);
	std::vector<Neuron*>* findNeuronsByValue(double);

private:
	int id;
	std::vector<Neuron*> neurons;
	int type; // LayerType - TODO: Find correct way to declare an enum 
			  // so that the data type of this variable can be set 
			  // LayerType and it can be visible in Layer.cpp too. 
			  // Don't forget to apply it in the constructor as well.
};

enum LayerType {
	input = 0, regular, output = 1
};