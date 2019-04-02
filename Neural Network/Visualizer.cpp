#include "Visualizer.h"
#include <SFML/Graphics.hpp>

Visualizer::Visualizer(NeuralNetwork* nn)
{
	this->nn = nn;

	numberOfLayers = nn->getNumberOfLayers();

	h = 600.0f;
	l = 800.0f;
	gap = 5.0f;
	padding = 10.0f;
	neuronDiameter = 15.0f;
	distanceBetweenLayers = 20.0f;

	networkVerticalOffset = 0.0f;
	networkHorizontalOffset = 0.0f;

	maxNeuronsInALayer = nn->getMaxNumberOfNeurons();

	networkRatio = (numberOfLayers * neuronDiameter + distanceBetweenLayers * (numberOfLayers - 1)) / (maxNeuronsInALayer * neuronDiameter + (maxNeuronsInALayer - 1)* gap);

	if (networkRatio < (l / h)) {
		networkVerticalOffset = 0;
		networkHorizontalOffset = l / 2.0 - padding - ((h - 2 * padding)*(2.5 * numberOfLayers - 1.5)) / (0.625 * maxNeuronsInALayer - 0.125);
	}
	else {
		networkHorizontalOffset = 0;
		networkVerticalOffset = ((l - 2 * padding)*(1.25* maxNeuronsInALayer - 0.25)) / (0.75 - 1.25*numberOfLayers) + h / 2.0 - padding;
	}
}

void Visualizer::init() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "Neural Network Visualizer");
	window.setVerticalSyncEnabled(true);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		window.draw(shape);
	
		window.display();
	}
}

void Visualizer::update() {

}

double Visualizer::getLayerVerticalOffset(int neuronCount) {
	return (maxNeuronsInALayer - neuronCount) * (neuronDiameter + distanceBetweenLayers) / 2.0;
}
