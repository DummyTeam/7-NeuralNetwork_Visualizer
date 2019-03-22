#include"Core.h"
#include"NeuralNetwork.h"
#include"Utils.h"
int main() {

	// Initialize random seed
	srand(10);

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

	// Training Stage
	double trainDataArr[] = { 0, 0, 0 };
	double trainDataArr2[] = { 1, 1, 0 };
	double trainDataArr3[] = { 0, 1, 1 };
	double trainDataArr4[] = { 1, 0, 1 };

	std::vector<std::vector<double>> trainingDataSet;

	trainingDataSet.push_back(std::vector<double>(trainDataArr, trainDataArr + sizeof(trainDataArr) / sizeof(double)));
	trainingDataSet.push_back(std::vector<double>(trainDataArr2, trainDataArr2 + sizeof(trainDataArr2) / sizeof(double)));
	trainingDataSet.push_back(std::vector<double>(trainDataArr3, trainDataArr3 + sizeof(trainDataArr3) / sizeof(double)));
	trainingDataSet.push_back(std::vector<double>(trainDataArr4, trainDataArr4 + sizeof(trainDataArr4) / sizeof(double)));

	neuralNetwork->train(trainingDataSet);

	// Predicting stage
	double inputArr[] = { 1, 2 };
	std::vector<double> input(inputArr, inputArr + sizeof(inputArr) / sizeof(double));
	std::vector<double> results = neuralNetwork->predict(input);

	std::cout << neuralNetwork->toString() << std::endl;

	system("pause");
	return 0;
}
