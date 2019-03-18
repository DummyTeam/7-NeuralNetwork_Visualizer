#pragma once

#include "Squishification.h"

class ReLU : public Squishification
{
public:
	ReLU(){}

	double squish(double value) {
		return (value*value) / 2.42; // TODO: Implement this properly
	}

};

