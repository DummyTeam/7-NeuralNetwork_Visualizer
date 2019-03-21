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
	std::vector<double> predict(std::vector<double>&);
	std::string toString();
	void buildWeightConnections();
private:
	int neuronIndex;
	std::vector<Layer*> layers;
};
