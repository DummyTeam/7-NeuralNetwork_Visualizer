#include "GradientDescent.h"
#include "NeuralNetwork.h"

GradientDescent::GradientDescent(CostFunction* cost)
{
	this->cost = cost;
}

void GradientDescent::setNeuralNetwork(NeuralNetwork* nn)
{
	this->nn = nn;
}

void GradientDescent::train(DataSet* dataSet, double learningRate, int numberOfIterations)
{
	for (size_t i = 0; i < numberOfIterations; i++)
	{
		Sample* s = dataSet->getRandomSample();

		nn->backPropogate(
			nn->predict(s->getInput()), // Output layer activation values after feedforward propogation
			s->getOutput(),				// Expected results
			learningRate		        // Learning rate
		);

		nn->printTheResult(i, s);
	}
}

double GradientDescent::calculateCost(std::vector<double> const & expectedValues) 
{
	double value = this->cost->calculate(expectedValues, nn->getLayers().at(nn->getLayers().size() - 1)->getListActivationValues());
	costHistory.push_back(value);
	return value;
}

const std::vector<double> & GradientDescent::getCostHistory()
{
	return costHistory;
}
