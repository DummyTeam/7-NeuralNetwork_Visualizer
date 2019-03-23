#include"Core.h"
#include"NeuralNetwork.h"
#include"Utils.h"
#include"DataSet.h"

int main() {

	// Initialize random seed
	srand(10);

	DataSet* dataSet = new DataSet("data.data", 2, 1);


	system("pause");

	// Create a neural network
	NeuralNetwork* neuralNetwork = new NeuralNetwork();

	// Create an input layer
	Layer* inputLayer = new Layer();

	// Add created neurons to the created input layer
	inputLayer->populateNeurons(2);

	// Add input layer to neural network
	neuralNetwork->addLayer(inputLayer);

	// Create hidden layer
	Layer* hiddenLayer = new Layer();
	Layer* hiddenLayer2 = new Layer();

	// Add created neurons to hidden layer
	hiddenLayer->populateNeurons(4);
	hiddenLayer2->populateNeurons(4);

	// Add hidden layer to neural network
	neuralNetwork->addLayer(hiddenLayer);
	neuralNetwork->addLayer(hiddenLayer2);

	// Create an output layer
	Layer* outputLayer = new Layer();

	// Add created neurons to output layer
	outputLayer->populateNeurons(1);

	// Add output layer to neural network
	neuralNetwork->addLayer(outputLayer);

	// Building relationships (weights and biases) amoung neurons
	neuralNetwork->buildWeightsAndBiases();

	// Train the network
	neuralNetwork->train(trainingDataSet);

	// Predicting stage
	double inputArr[] = { 1, 2 };
	std::vector<double> input(inputArr, inputArr + sizeof(inputArr) / sizeof(double));
	std::vector<double> results = neuralNetwork->predict(input);

	std::cout << neuralNetwork->toString() << std::endl;

	system("pause");
	return 0;
}
