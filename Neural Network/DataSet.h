#pragma once

#include "Sample.h"

class DataSet
{
public:

	DataSet(std::string path, int sizeOfInput, int sizeOfOutput);
	DataSet(std::string path, int sizeOfInput, int sizeOfOutput, int numberOfOriginalCases, int numberOfIterations);

	std::vector<Sample*>& getDataSet();

private:

	std::vector<Sample*> dataSet;

	std::string path;

	int sizeOfInput;

	int sizeOfOutput;

	void readFromFile();

	void shuffleInput(int numberOfOriginalCases, int numberOfIterations);

};
