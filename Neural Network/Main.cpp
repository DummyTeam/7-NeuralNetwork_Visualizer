#include "Core.h"
#include "Xor.h"
#include "ReLU.h"
#include "MSE.h"
#include "GradientDescent.h"
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
	int numberOfInputs = 4;
	int numberOfHiddenLayerNodes = 8;
	int numberOfHiddenLayerNodes2 = 8;
	int numberOfOutputs = 1;

	NeuralNetwork* nn = (new NeuralNetwork::Builder())
		->addLayer(new Layer(numberOfInputs))
		->addLayer(new Layer(numberOfHiddenLayerNodes, new ReLU()))
		->addLayer(new Layer(numberOfHiddenLayerNodes2, new ReLU()))
		->addLayer(new Layer(numberOfOutputs, new ReLU()))
		->setLearningMethod(new GradientDescent(new MSE()))
		->build();

	DataSet* trainingDataSet = new DataSet("data4.data", numberOfInputs, numberOfOutputs);
	DataSet* testingDataSet = new DataSet("data4Test.data", numberOfInputs, numberOfOutputs);

	NNVisualAdapter* nnVisualAdapter = new NNVisualAdapter(nn);
	NNGraphAdapter* graphAdapter = new NNGraphAdapter(nn);

	MainWindow* mainWindow = new MainWindow();
	mainWindow->addAdapter(nnVisualAdapter);
	mainWindow->addAdapter(graphAdapter);

	// Starts a new view thread!
	mainWindow->startWindow();

	double learningRate = 0.0314;
	int numberOfIterations = 7000;

	nn->train(
		trainingDataSet,
		learningRate,
		numberOfIterations
	);

	nn->test(testingDataSet);

	system("pause");
	return 0;
}