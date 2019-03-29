#pragma once

#include <vector>
#include <string>

class Sample
{
public:
	Sample(std::string line, int sizeOfInput, int sizeOfOutput);

	std::vector<double>& getInput();
	std::vector<double>& getOutput();

	void pushToInput(double);
	void pushToOutput(double);

	void splitInputAndOutput();
	Sample* clone();

private:
	std::vector<double> input;
	std::vector<double> output;

	size_t sizeOfInput;
	size_t sizeOfOutput;
	std::string line;
};

