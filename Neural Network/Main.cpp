#include "Core.h"
#include "Xor.h"
#include "ReLU.h"
#include "MainWindow.h"
#include "NNVisualAdapter.h"
#include "NNGraphAdapter.h"

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

	DataSet* trainingDataSet = new DataSet("newDataSet.data", numberOfInputs, numberOfOutputs);
	DataSet* testingDataSet = new DataSet("newDataSetTest.data", numberOfInputs, numberOfOutputs);

	NNVisualAdapter* nnVisualAdapter = new NNVisualAdapter(nn);
	NNGraphAdapter* graphAdapter = new NNGraphAdapter(nn);

	MainWindow* mainWindow = new MainWindow();
	mainWindow->addAdapter(nnVisualAdapter);
	mainWindow->addAdapter(graphAdapter);

	//// Starts a new view thread!
	mainWindow->startWindow();

	double learningRate = 0.003;
	int numberOfIterations = 1000;

	nn->train(
		trainingDataSet,
		learningRate,
		numberOfIterations
	);

	nn->test(testingDataSet);

	system("pause");
	return 0;
}
