#include"DataSet.h"
#include <fstream>
#include"Utils.h"
DataSet::DataSet(std::string path, int sizeOfInput, int sizeOfOutput)
{
	this->path = path;
	this->sizeOfInput = sizeOfInput;
	this->sizeOfOutput = sizeOfOutput;
	shuffleInput(4, 50000);
}

void DataSet::readFromFile() {

	std::string line;

	std::ifstream dataFile(this->path);

	if (dataFile.is_open())
	{
		while (getline(dataFile, line))
		{
			this->dataSet.push_back(new Sample(line, sizeOfInput, sizeOfOutput));
		}
		dataFile.close();
	}
	else printf("Unable to open file");
}

void DataSet::shuffleInput(int numberOfOriginalCases, int numberOfIterations) {
	if (numberOfIterations <= 0 || numberOfOriginalCases <= 0)
		throw "Number of iterations and number of original cases must be greater than 0 in DataSet::shuffleInput(int)\n";

	std::string line;

	std::ifstream dataFile(this->path);

	std::vector<std::string> cases;

	if (dataFile.is_open())
	{
		while (getline(dataFile, line))
		{
			cases.push_back(line);
		}
		dataFile.close();
	}
	else printf("Unable to open file");

	for (size_t i = 0; i < numberOfIterations; i++) {
		this->dataSet.push_back(new Sample(cases[Utils::randomNumberInt(0, numberOfOriginalCases - 1)], sizeOfInput, sizeOfOutput));
	}
}


std::vector<Sample*>& DataSet::getDataSet() {
	return this->dataSet;
}