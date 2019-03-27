#include"Core.h"
#include"NeuralNetwork.h"
#include"Utils.h"
#include"DataSet.h"
#include"ReLU.h"
#include"Sigmoid.h"

int main() {
	// Initialize random seed
	srand(24);

	// Initialize variables
	double learningRate = 0.1;
	double numberOfInputs = 22;
	double numberOfOutputs = 1;
	double numberOfOriginalCases = 76;
	double numberOfIterations = 1000;

	// If no shuffle is needed then use simple constructor
	// DataSet* dataSet = new DataSet("data.data", numberOfInputs, numberOfOutputs);

	// Prepare shuffled data set
	DataSet* dataSet = new DataSet("newDataSet.data", numberOfInputs, numberOfOutputs, numberOfOriginalCases, numberOfIterations);

	DataSet* testDataSet = new DataSet("testDataSet.data", numberOfInputs, numberOfOutputs);

	// Create a neural network
	NeuralNetwork* neuralNetwork = new NeuralNetwork();

	// Create an input layer
	Layer* inputLayer = new Layer();

	// Add created neurons to the created input layer
	inputLayer->populateNeurons(numberOfInputs, neuralNetwork);

	// Add input layer to neural network
	neuralNetwork->addLayer(inputLayer);

	// Create hidden layer
	Layer* hiddenLayer = new Layer();
	Layer* hiddenLayer2 = new Layer();
	Layer* hiddenLayer3 = new Layer();

	// Add created neurons to hidden layer
	hiddenLayer->populateNeurons(16, neuralNetwork);
	hiddenLayer2->populateNeurons(16, neuralNetwork);
	hiddenLayer3->populateNeurons(8, neuralNetwork);

	// Add hidden layer to neural network
	neuralNetwork->addLayer(hiddenLayer);
	neuralNetwork->addLayer(hiddenLayer2);
	neuralNetwork->addLayer(hiddenLayer3);

	// Create an output layer
	Layer* outputLayer = new Layer(new ReLU()); // new ReLU()

	// Add created neurons to output layer
	outputLayer->populateNeurons(numberOfOutputs, neuralNetwork);

	// Add output layer to neural network
	neuralNetwork->addLayer(outputLayer);

	// Building relationships (weights and biases) amoung neurons
	neuralNetwork->buildWeightsAndBiases();

	// Train the network
	neuralNetwork->train(dataSet, learningRate);

	std::cout << neuralNetwork->toString() << std::endl << std::endl;
	std::cout << "Start prediction!" << std::endl;

	for (std::vector<Sample*>::iterator trainingSample = testDataSet->getDataSet().begin(); trainingSample != testDataSet->getDataSet().end(); trainingSample++) {
		std::vector<double> res = neuralNetwork->predict((*trainingSample)->getInput());

		for (size_t i = 0; i < res.size(); i++)
		{
			std::cout << res[i] << std::endl;
		}
	}

	system("pause");
	return 0;
}
