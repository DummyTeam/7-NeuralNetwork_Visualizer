#include"Core.h"
#include"NeuralNetwork.h"
#include"Utils.h"
#include"DataSet.h"
#include"ReLU.h"
#include"Sigmoid.h"

int main() {

	// Initialize random seed
	srand(10);

	DataSet* dataSet = new DataSet("data.data", 2, 1);

	double learningRate = 0.2;

	// Create a neural network
	NeuralNetwork* neuralNetwork = new NeuralNetwork();

	// Create an input layer
	Layer* inputLayer = new Layer();

	// Add created neurons to the created input layer
	inputLayer->populateNeurons(2, neuralNetwork);

	// Add input layer to neural network
	neuralNetwork->addLayer(inputLayer);

	// Create hidden layer
	Layer* hiddenLayer = new Layer(new Sigmoid());
	//Layer* hiddenLayer2 = new Layer();

	// Add created neurons to hidden layer
	hiddenLayer->populateNeurons(2, neuralNetwork);
	//hiddenLayer2->populateNeurons(3, neuralNetwork);

	// Add hidden layer to neural network
	neuralNetwork->addLayer(hiddenLayer);
	//neuralNetwork->addLayer(hiddenLayer2);

	// Create an output layer
	Layer* outputLayer = new Layer(new ReLU());

	// Add created neurons to output layer
	outputLayer->populateNeurons(1, neuralNetwork);

	// Add output layer to neural network
	neuralNetwork->addLayer(outputLayer);

	// Building relationships (weights and biases) amoung neurons
	neuralNetwork->buildWeightsAndBiases();

	// Train the network
	neuralNetwork->train(dataSet, learningRate);

	std::cout << neuralNetwork->toString() << std::endl;

	system("pause");
	return 0;
}
