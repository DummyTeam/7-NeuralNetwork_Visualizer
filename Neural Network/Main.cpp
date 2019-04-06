#include "Core.h"
#include "Xor.h"
#include "ReLU.h"
#include "MainWindow.h"
#include "NNVisualAdapter.h"

int main()
{
	// Initialize random seed
	srand(24);

	// Alternative 1: Neural Network for XOR
	Xor* x = new Xor("data2.data", 0.1, 2000);
	x->train();
	x->viewNetwork();

	printf("\n");
	system("pause");

	// Alternative 2: Neural Network for XOR
	int numberOfInputs = 4;
	int numberOfHiddenLayerNodes = 8;
	int numberOfHiddenLayerNodes2 = 8;
	int numberOfOutputs = 1;

	NeuralNetwork* nn = (new NeuralNetwork::Builder())
		->addLayer(new Layer(numberOfInputs))
		->addLayer(new Layer(numberOfHiddenLayerNodes, new ReLU()))
		->addLayer(new Layer(numberOfHiddenLayerNodes2, new ReLU()))
		->addLayer(new Layer(numberOfOutputs, new ReLU()))
		->build();

	NNVisualAdapter* nnVisualAdapter = new NNVisualAdapter(nn);

	MainWindow* mainWindow = new MainWindow();
	mainWindow->addSubscriber(nnVisualAdapter);

	// Starts a new view thread!
	mainWindow->startWindow();

	double learningRate = 0.06;
	int numberOfIterations = 30000;

	nn->train(
		new DataSet("data4.data", numberOfInputs, numberOfOutputs),
		learningRate,
		numberOfIterations
	);

	nn->test(new DataSet("data4Test.data", numberOfInputs, numberOfOutputs));

	system("pause");

	return 0;
}
