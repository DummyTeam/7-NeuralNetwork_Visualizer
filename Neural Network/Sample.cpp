#include "Sample.h"
#include <sstream>

Sample::Sample(std::string line, int sizeOfInput, int sizeOfOutput)
{
	this->sizeOfInput = sizeOfInput;
	this->sizeOfOutput = sizeOfOutput;
	this->line = line;
	this->splitInputAndOutput();
}

std::vector<double> Sample::getInput()
{
	return this->input;
}

std::vector<double> Sample::getOutput()
{
	return this->output;
}

void Sample::pushToInput(double inputItem) {
	this->input.push_back(inputItem);
}

void Sample::pushToOutput(double outputItem) {
	this->output.push_back(outputItem);
}


void Sample::splitInputAndOutput()
{
	std::stringstream ss(this->line);
	double num;

	for (size_t i = 0; i < this->sizeOfInput; i++)
	{
		ss >> num;
		this->input.push_back(num);
	}

	for (size_t i = 0; i < this->sizeOfOutput; i++)
	{
		ss >> num;
		this->output.push_back(num);
	}
}