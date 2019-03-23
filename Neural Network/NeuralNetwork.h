#pragma once

#include"Layer.h"
#include"DataSet.h"
#include<vector>
#include<string>

class NeuralNetwork
{
public:

	NeuralNetwork();
	int getNeuronIndex();
	void addLayer(Layer*);
	void backPropogate(std::vector<double>&, std::vector<double>&);
	std::vector<double> predict(std::vector<double>&);
	void train(DataSet*);
	std::string toString();
	void buildWeightsAndBiases();
private:
	int neuronIndex;
	std::vector<Layer*> layers;
};
