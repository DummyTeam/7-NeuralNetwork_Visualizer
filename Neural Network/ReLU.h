#pragma once

#include "Squishification.h"

class ReLU : public Squishification
{
public:
	ReLU() {}

	double squish(double value) {
		if (value <= 0)
			return 0;
		return value;
	}

	double derivative(double value) {
		if (value <= 0)
			return 0;
		return 1;
	}

};