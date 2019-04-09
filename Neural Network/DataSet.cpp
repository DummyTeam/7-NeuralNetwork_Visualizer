#include <fstream>
#include"DataSet.h"
#include"Utils.h"

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
			this->dataSet.push_back(new Sample(line, sizeOfInput, sizeOfOutput));
		}
		dataFile.close();
	}
	else printf("Unable to open file");
}


Sample* DataSet::getRandomSample() {
	if (this->dataSet.size() <= 0)
		throw "No data in data in DataSet!";

	return this->dataSet.at(Utils::randomNumberInt(0, this->dataSet.size() - 1));
}

std::vector<Sample*>& DataSet::getDataSet() {
	return this->dataSet;
}

