# 7-NeuralNetwork_OO
Neural Network Implemented in C++: An Object Oriented Approach From Scratch

### Sample Code

The sample code below shows how Neural Network can be built in the project:

```cpp
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
```


### Class Diagram

![Screen from program](https://raw.githubusercontent.com/DummyTeam/7-NeuralNetwork_OO/master/art/classDiagram.PNG)


### Tools

  - Visual Studio
  - C++
