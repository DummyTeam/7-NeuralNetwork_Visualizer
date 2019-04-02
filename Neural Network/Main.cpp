#include "Core.h"
#include "Xor.h"
#include "ReLU.h"
#include "Visualizer.h"

int main()
{



	//// Initialize random seed
	//srand(24);

	//// Alternative 1: Neural Network for XOR
	////Xor* x = new Xor("data.data", 0.1, 52000);
	////x->train();
	////x->viewNetwork();

	//printf("\n");
	//system("pause");

	//// Alternative 2: Neural Network for XOR
	//int numberOfInputs = 22;
	//int numberOfHiddenLayerNodes = 16;
	//int numberOfHiddenLayerNodes2 = 8;
	//int numberOfOutputs = 1;

	//NeuralNetwork* nn = (new NeuralNetwork::Builder())
	//	->addLayer(new Layer(numberOfInputs))
	//	->addLayer(new Layer(numberOfHiddenLayerNodes))
	//	->addLayer(new Layer(numberOfHiddenLayerNodes2))
	//	->addLayer(new Layer(numberOfOutputs, new ReLU()))
	//	->build();

	//double learningRate = 0.06;
	//int numberOfIterations = 200000;

	//nn->train(
	//	new DataSet("newDataSet.data", numberOfInputs, numberOfOutputs),
	//	learningRate,
	//	numberOfIterations
	//);

	//system("pause");

	//nn->test(new DataSet("newDataSetTest.data", numberOfInputs, numberOfOutputs));

	system("pause");

	return 0;
}
