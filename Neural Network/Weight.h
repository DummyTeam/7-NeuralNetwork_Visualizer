#pragma once

class Weight
{
public:
	Weight();
	~Weight();

	Weight(double value);
	Weight(double value, int from, int to);

	void setValue(double value);

private:
	double value;
	int from;		// from which neuron (id)
	int to;			// to which neuron (id)
};
