#pragma once

#include "Sample.h"

class DataSet
{
public:
	DataSet(std::string path, int sizeOfInput, int sizeOfOutput);
	void readFromFile();

private:
	std::vector<Sample> dataSet;
	std::string path;
	int sizeOfInput;
	int sizeOfOutput;
};
