#pragma once

#include"Layer.h"
#include<vector>

class NeuralNetwork
{
public:
	NeuralNetwork();
	int getNeuronIndex();
	std::vector<double>* predict(std::vector<double>&);
	
private:
	int neuronIndex;
	std::vector<Layer*> layers;

	void randomizeWeightsBiases();
};
