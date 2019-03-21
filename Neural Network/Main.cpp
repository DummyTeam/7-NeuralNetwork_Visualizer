#include"Core.h"
#include"NeuralNetwork.h"

int main() {

	// Create a neural network
	NeuralNetwork* neuralNetwork = new NeuralNetwork();

	// Create an input layer
	Layer* inputLayer = new Layer();

	// Add created neurons to the created input layer
	inputLayer->populateNeurons(2);

	// Add input layer to neural network
	neuralNetwork->addLayer(inputLayer);

	// Create a hidden layer
	Layer* hiddenLayer = new Layer();

	// Add created neurons to hidden layer
	hiddenLayer->populateNeurons(4);

	// Add hidden layer to neural network
	neuralNetwork->addLayer(hiddenLayer);

	// Create an output layer
	Layer* outputLayer = new Layer();

	// Add created neurons to output layer
	outputLayer->populateNeurons(3);

	// Add output layer to neural network
	neuralNetwork->addLayer(outputLayer);

	std::cout << neuralNetwork->toString() << std::endl;

	system("pause");
	return 0;
}
