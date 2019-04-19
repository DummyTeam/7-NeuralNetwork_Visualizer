#include "MSE.h"
#include <vector>
#include <cmath>

MSE::MSE()
{
	//std::vector<double> const &
}

double MSE::calculate(std::vector<double> const & expectedValues, std::vector<double> const & values) {
	if (expectedValues.size() != values.size())
		throw "Cannot calculate the cost. Number of expected outputs does not match with number of output layer neurons";

	double cost = 0;

	for (size_t i = 0; i < expectedValues.size(); i++) {
		cost += pow((values[0] - expectedValues[0]), 2);
	}

	return cost;
}