#pragma once

#include <vector>

class CostFunction
{
public:
	virtual double calculate(std::vector<double> const &, std::vector<double> const &) = 0;
};