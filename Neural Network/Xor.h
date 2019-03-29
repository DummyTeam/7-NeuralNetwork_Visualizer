#pragma once

#include <string>
#include"NeuralNetwork.h"

class Xor
{
public:
	Xor();
	Xor(std::string, double, int);

	void init();
	void train();
	void viewNetwork();

private:
	std::string dataPath;
	double learningRate;
	int numberOfIterations;
	NeuralNetwork* neuralNetwork;
	DataSet* dataSet;

};

