#pragma once

#include "Sample.h"

class DataSet
{
public:
	DataSet(std::string path, int sizeOfInput, int sizeOfOutput);
	std::vector<Sample*>& getDataSet();

	Sample* getRandomSample();
	
private:
	std::vector<Sample*> dataSet;
	std::vector<std::string> strings;
	std::string path;
	int sizeOfInput;
	int sizeOfOutput;
	void readFromFile();
};
