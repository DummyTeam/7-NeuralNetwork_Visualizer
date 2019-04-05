#include "Core.h"
#include "Xor.h"
#include "ReLU.h"
#include "Visualizer.h"

int main()
{
	// Initialize random seed
	//srand(24);

	// Alternative 1: Neural Network for XOR
	/*Xor* x = new Xor("data2.data", 0.1, 12000);
	x->train();
	x->viewNetwork();
*/
	printf("\n");
	system("pause");

	// Alternative 2: Neural Network for XOR
	int numberOfInputs = 4;
	int numberOfHiddenLayerNodes = 4;
	int numberOfHiddenLayerNodes2 = 2;
	int numberOfOutputs = 1;

	NeuralNetwork* nn = (new NeuralNetwork::Builder())
		->addLayer(new Layer(numberOfInputs))
		->addLayer(new Layer(numberOfHiddenLayerNodes))
		->addLayer(new Layer(numberOfHiddenLayerNodes2))
		->addLayer(new Layer(numberOfOutputs, new ReLU()))
		->build();

	double learningRate = 0.09;
	int numberOfIterations = 5000;

	nn->train(
		new DataSet("data4.data", numberOfInputs, numberOfOutputs),
		learningRate,
		numberOfIterations
	);

	Visualizer* visualizer = new Visualizer(nn->getNumberOfLayers(), nn->getMaxNumberOfNeurons());
	visualizer->addSubscriber(nn);
	visualizer->drawNetwork();

	nn->test(new DataSet("data4Test.data", numberOfInputs, numberOfOutputs));

	system("pause");

	return 0;
}
