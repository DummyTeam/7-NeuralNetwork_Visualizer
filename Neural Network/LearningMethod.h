#pragma once

#include "DataSet.h"
#include "CostFunction.h"

class NeuralNetwork;

class LearningMethod
{
public:
	virtual void train(DataSet*, double, int) = 0;
	virtual void setNeuralNetwork(NeuralNetwork*) = 0;
	virtual double calculateCost(std::vector<double> const &) = 0;
	virtual std::vector<double> & getCostHistory() = 0;
	virtual double getCurrentCost() = 0;

protected:
	CostFunction* cost;
	NeuralNetwork* nn;
	std::vector<double> costHistory;
};
