#pragma once

#include <vector>
#include <string>

class Sample
{
public:
	Sample(std::string line, int sizeOfInput, int sizeOfOutput);

	std::vector<double> getInput();
	std::vector<double> getOutput();

	void pushToInput(double);
	void pushToOutput(double);

	void splitInputAndOutput(std::string);

private:
	std::vector<double> input;
	std::vector<double> output;

	int sizeOfInput;
	int sizeOfOutput;
	std::string line;
};

