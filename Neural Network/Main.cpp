#include "Core.h"
#include "Xor.h"
#include "ReLU.h"
#include "MainWindow.h"
#include "NNVisualAdapter.h"

int main()
{
	// Initialize random seed
	srand(24);

	printf("\n");
	system("pause");

	// Alternative 2: Neural Network for XOR
	int numberOfInputs = 22;
	int numberOfHiddenLayerNodes = 16;
	int numberOfHiddenLayerNodes2 = 16;
	int numberOfOutputs = 1;

	NeuralNetwork* nn = (new NeuralNetwork::Builder())
		->addLayer(new Layer(numberOfInputs))
		->addLayer(new Layer(numberOfHiddenLayerNodes))
		->addLayer(new Layer(numberOfHiddenLayerNodes2))
		->addLayer(new Layer(numberOfOutputs, new ReLU()))
		->build();

	NNVisualAdapter* nnVisualAdapter = new NNVisualAdapter(nn);

	MainWindow* mainWindow = new MainWindow();
	mainWindow->addAdapter(nnVisualAdapter);

	//// Starts a new view thread!
	mainWindow->startWindow();

	double learningRate = 0.003;
	int numberOfIterations = 1000;

	nn->train(
		new DataSet("newDataSet.data", numberOfInputs, numberOfOutputs),
		learningRate,
		numberOfIterations
	);

	nn->test(new DataSet("newDataSetTest.data", numberOfInputs, numberOfOutputs));

	system("pause");
	return 0;
}
