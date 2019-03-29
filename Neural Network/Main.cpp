#include "Core.h"
#include "Xor.h"

int main()
{
	// Initialize random seed
	srand(24);

	// Alternative 1: Neural Network for XOR
	Xor* x = new Xor("data.data", 0.1, 52000);
	x->train();
	x->viewNetwork();

	printf("\n\n\n");
	system("pause");

	// Alternative 2: Neural Network for XOR
	int numberOfInputs = 2;
	int numberOfHiddenLayerNodes = 2;
	int numberOfOutputs = 1;

	NeuralNetwork* nn = (new NeuralNetwork::Builder())
		->addLayer(new Layer(numberOfInputs))
		->addLayer(new Layer(numberOfHiddenLayerNodes))
		->addLayer(new Layer(numberOfOutputs))
		->build();

	double learningRate = 0.1;
	int numberOfIterations = 20000;

	nn->train(
		new DataSet("data.data", numberOfInputs, numberOfOutputs), 
		learningRate, 
		numberOfIterations
	);

	system("pause");
	return 0;
}
