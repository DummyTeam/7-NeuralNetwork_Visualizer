<h1 align="center">
  <br>
  <a href="https://github.com/DummyTeam/7-NeuralNetwork_OO"><img src="https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/NN_Logo_Design_main.jpg" alt="Neural Network Visualizer" width="400"></a>
  <br>
  Neural Network Visualizer
  <br>
</h1>

<h4 align="center">Neural Network Implemented in C++: An Object Oriented Approach From Scratch with Visualizing tools built on top of <a href="https://github.com/SFML/SFML" target="_blank">SFML</a>.</h4>

<p align="center">
  <a href="https://github.com/DummyTeam/7-NeuralNetwork_OO">
    <img src="https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/animNeuralNetwork.gif" alt="Neural Network Visualizer"
         alt="Neural network animation">
  </a>
</p>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#example">Example</a> •
  <a href="#credits">Structure</a> •
  <a href="#related">Visualization</a> •
  <a href="#license">Credits</a>
  <a href="#license">License</a>
</p>

![screenshot](https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/animNeuralNetwork.gif)


# 7-NeuralNetwork_OO


### Sample Code

The sample code below shows how Neural Network can be built in the project:

```cpp
	int numberOfInputs = 4;
	int numberOfHiddenLayerNodes = 8;
	int numberOfHiddenLayerNodes2 = 8;
	int numberOfOutputs = 1;

	NeuralNetwork* nn = (new NeuralNetwork::Builder())
		->addLayer(new Layer(numberOfInputs))
		->addLayer(new Layer(numberOfHiddenLayerNodes, new ReLU()))
		->addLayer(new Layer(numberOfHiddenLayerNodes2, new ReLU()))
		->addLayer(new Layer(numberOfOutputs, new ReLU()))
		->setLearningMethod(new GradientDescent(new MSE())) // Cost Function
		->build();

	DataSet* trainingDataSet = new DataSet("data4.data", numberOfInputs, numberOfOutputs);
	
	NNVisualAdapter* nnVisualAdapter = new NNVisualAdapter(nn);
	NNGraphAdapter* graphAdapter = new NNGraphAdapter(nn, new LastNRange(400, 170)); //  new FullRange LastNRange(800, 170)

	Window* nnWindow = new Window(sf::Vector2i(700, 600), sf::Vector2i(20, 50), "Neural Network Structure");
	nnWindow->addAdapter(nnVisualAdapter);

	Window* graphWindow = new Window(sf::Vector2i(800, 600), sf::Vector2i(720, 50), "Cost Graph");
	graphWindow->addAdapter(graphAdapter);

	// Starts new view threads!
	nnWindow->startWindow();
	graphWindow->startWindow();

	double learningRate = 0.0314;
	int numberOfIterations = 7000;
	
	nn->train(
		trainingDataSet,
		learningRate,
		numberOfIterations
	);

	DataSet* testingDataSet = new DataSet("data4Test.data", numberOfInputs, numberOfOutputs);
	nn->test(testingDataSet);
```


### Class Diagram

![Screen from program](https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/classDiagram.PNG)


### Tools

  - Visual Studio
  - C++
