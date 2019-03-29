#pragma once

#include "Sample.h"

class DataSet
{
public:
	DataSet(std::string path, int sizeOfInput, int sizeOfOutput);
	DataSet(std::string path, int sizeOfInput, int sizeOfOutput, int numberOfOriginalCases, int numberOfIterations);
	std::vector<Sample*>& getDataSet();

	Sample* getRandomSample();

	// Obsolete: This method was used to generate inefficient input data
	void shuffleInput(int, size_t);

private:
	std::vector<Sample*> dataSet;
	std::vector<std::string> strings;
	std::string path;
	int sizeOfInput;
	int sizeOfOutput;
	void readFromFile();
};
