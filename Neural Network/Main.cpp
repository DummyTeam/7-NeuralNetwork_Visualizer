#include "Core.h"
#include "ReLU.h"
#include "MSE.h"
#include "FullRange.h"
#include "LastNRange.h"
#include "GradientDescent.h"
#include "Window.h"
#include "NNVisualAdapter.h"
#include "NNGraphAdapter.h"

int main()
{
	// Initialize random seed
	srand(24);

	// Neural Network for XOR
	int numberOfInputs = 8;
	int numberOfHiddenLayerNodes = 4;
	int numberOfHiddenLayerNodes2 = 2;
	int numberOfHiddenLayerNodes3 = 4;
	int numberOfOutputs = 1;

	NeuralNetwork* nn = (new NeuralNetwork::Builder())
		->addLayer(new Layer(numberOfInputs))
		->addLayer(new Layer(numberOfHiddenLayerNodes, new ReLU()))
		->addLayer(new Layer(numberOfHiddenLayerNodes2, new ReLU()))
		->addLayer(new Layer(numberOfHiddenLayerNodes3, new ReLU()))
		->addLayer(new Layer(numberOfOutputs, new ReLU()))
		->setLearningMethod(new GradientDescent(new MSE())) // Cost Function
		->build();

	DataSet* trainingDataSet = new DataSet("data4.data", numberOfInputs, numberOfOutputs);
	DataSet* testingDataSet = new DataSet("data4Test.data", numberOfInputs, numberOfOutputs);

	NNVisualAdapter* nnVisualAdapter = new NNVisualAdapter(nn);
	NNGraphAdapter* graphAdapter = new NNGraphAdapter(nn, new LastNRange(400, 170)); //new FullRange LastNRange(800, 170)

	Window* nnWindow = new Window(sf::Vector2i(700, 600), sf::Vector2i(20, 50), "Neural Network Structure");
	nnWindow->addAdapter(nnVisualAdapter);

	// TODO: Fix y axis values
	Window* graphWindow = new Window(sf::Vector2i(800, 600), sf::Vector2i(720, 50), "Cost Graph");
	graphWindow->addAdapter(graphAdapter);

	// Starts new view threads!
	nnWindow->startWindow();
	graphWindow->startWindow();

	double learningRate = 0.0314;
	int numberOfIterations = 7000;
	
	system("pause");

	nn->train(
		trainingDataSet,
		learningRate,
		numberOfIterations
	);

	// TODO: Make this work!
	//nn->saveNetwork("previousNeuralNetwork.nn");

	nn->test(testingDataSet);

	system("pause");
	return 0;
}