#pragma once

#include "CostFunction.h"

class MSE : public CostFunction
{
public:
	MSE();
	double calculate(std::vector<double> const &, std::vector<double> const &);

};