#pragma once

#include "Squishification.h"

class Sigmoid : public Squishification
{
public:
	Sigmoid(){}

	double squish(double value) {
		return (value*value) / 5.42; // TODO: Implement this properly
	}

};