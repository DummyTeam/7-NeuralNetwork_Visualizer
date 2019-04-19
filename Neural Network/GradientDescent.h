#pragma once

#include "LearningMethod.h"

class NeuralNetwork;

class GradientDescent : public LearningMethod
{
public:
	GradientDescent(CostFunction* cost);
	void train(DataSet*, double, int);
	void setNeuralNetwork(NeuralNetwork*);
	double calculateCost(std::vector<double> const &);
	const std::vector<double> &  getCostHistory();

};
