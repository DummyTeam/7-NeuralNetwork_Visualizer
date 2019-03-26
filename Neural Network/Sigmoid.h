#pragma once

#include "Squishification.h"
#include "Math.h"

class Sigmoid : public Squishification
{
public:
	Sigmoid() {}

	double squish(double value) {
		if (value > 15)
			return 1;
		else if (value <= -15)
			return 0;
		else
			return (exp(value)) / (exp(value) + 1) * 1.0;
	}

	double derivative(double value) {
		return (1.0 * squish(value) * (1.0 - squish(value)));
	}
};