#include"DataSet.h"
#include <fstream>

DataSet::DataSet(std::string path, int sizeOfInput, int sizeOfOutput)
{
	this->path = path;
	this->sizeOfInput = sizeOfInput;
	this->sizeOfOutput = sizeOfOutput;
	readFromFile();
}

void DataSet::readFromFile() {

	std::string line;

	std::ifstream dataFile(this->path);

	if (dataFile.is_open())
	{
		while (getline(dataFile, line))
		{
			this->dataSet.push_back(Sample(line, sizeOfInput, sizeOfOutput));
		}
		dataFile.close();
	}
	else printf("Unable to open file");
}

std::vector<Sample>* DataSet::getDataSet() {
	return &(this->dataSet);
}