<h1 align="center">
  <br>
  <a href="https://github.com/DummyTeam/7-NeuralNetwork_OO"><img src="https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/NN_Logo_Design_main.jpg" alt="Neural Network Visualizer" width="400"></a>
  <br>
  Neural Network Visualizer
  <br>
</h1>

<h4 align="center">Neural Network Implemented in C++: An Object Oriented Approach From Scratch With Visualizing Tools Built on Top of <a href="https://github.com/SFML/SFML" target="_blank">SFML</a> Graphics Library.</h4>

<p align="center">
  <a href="#key-features">Key Features</a> •
  <a href="#sample-code">Sample Code</a> •
  <a href="#structure">Structure</a> •
  <a href="#visualization">Visualization</a> •
  <a href="#graph">Graph</a> •
  <a href="#credits">Credits</a> •
  <a href="#tools">Tools</a> •
  <a href="#license">License</a>
</p>

<p align="center">
  <a href="https://github.com/DummyTeam/7-NeuralNetwork_OO">
    <img src="https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/animNeuralNetwork.gif" alt="Neural Network Visualizer"
         alt="Neural network animation">
  </a>
</p>


## Key Features

* Easy to build a neural network 
* Apply different learning methods
* Various cost functions
* Activation functions
  - For all neurons in a layer
  - For individual neurons
* Train using multiple datasets
* Trainign using multiple datasets
* Visualizing activation values and weights
* Visualizing cost in graph as the neural network gets trained and tested 
  - For all neurons in a layer



## Sample Code

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
		->setLearningMethod(new GradientDescent(new MSE())) // Mean Squared Error
		->build();

	DataSet* trainingDataSet = new DataSet("data4.data", numberOfInputs, numberOfOutputs);
	
	NNVisualAdapter* nnVisualAdapter = new NNVisualAdapter(nn);
	NNGraphAdapter* graphAdapter = new NNGraphAdapter(nn, new LastNRange(400, 170));

	Window* nnWindow = new Window(
								sf::Vector2i(700, 600), 	// Screen dimensions
								sf::Vector2i(20, 50), 		// Screen position
								"Neural Network Structure"	// Screen title
								);
								
	nnWindow->addAdapter(nnVisualAdapter);

	Window* graphWindow = new Window(
								sf::Vector2i(800, 600), 	// Screen dimensions
								sf::Vector2i(720, 50),      // Screen position
								"Cost Graph"                // Screen title
								);
								
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


## Structure

![Screen from program](https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/WholeClassDiagram.jpg)



## Visualization


![Screen from program](https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/animNeuralNetwork.gif)


## Graph

Graph illustrating only last `n` number of the cost data:

![Screen from program](https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/graphLastNRange.gif)


Graph containing all the cost data at once:

![Screen from program](https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/graphFullRange.gif)



## Credits

  - [SFML](https://github.com/SFML/SFML)


## Tools

  - Visual Studio
  - C++


## License

MIT

---

> GitHub [@emiraslan](https://github.com/emiraslan) &nbsp;&middot;&nbsp;
> GitHub [DummyTeam](https://github.com/DummyTeam) &nbsp;&middot;&nbsp;
