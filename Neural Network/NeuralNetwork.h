#pragma once

#include"Layer.h"
#include<vector>
#include<string>

class NeuralNetwork
{
public:
	NeuralNetwork();
	int getNeuronIndex();
	void addLayer(Layer*);
	std::vector<double>* predict(std::vector<double>&);
	void initializeWeightsBiases();
	std::string toString();
private:
	int neuronIndex;
	std::vector<Layer*> layers;
};
