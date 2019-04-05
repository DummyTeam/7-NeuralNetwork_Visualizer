#include "Visualizer.h"
#include <SFML/Graphics.hpp>

Visualizer::Visualizer(int numberOfLayers, int maxNumberOfNeurons)
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Neural Network Visualizer", sf::Style::Default, settings);

	numberOfLayers = numberOfLayers;

	h = 600.0f;
	l = 800.0f;
	gap = 5.0f;
	padding = 10.0f;
	neuronDiameter = 20.0f;
	distanceBetweenLayers = 20.0f;

	networkVerticalOffset = 0.0f;
	networkHorizontalOffset = 0.0f;

	maxNeuronsInALayer = maxNumberOfNeurons;

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

void Visualizer::drawNetwork() {
	window->setVerticalSyncEnabled(true);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear(sf::Color::Black);
		for (auto& elem : this->subscribers) {
			elem->draw(this->window);
		}
		window->display();
	}
}

double Visualizer::getLayerVerticalOffset(int neuronCount) {
	return (maxNeuronsInALayer - neuronCount) * (neuronDiameter + distanceBetweenLayers) / 2.0;
}

void Visualizer::addSubscriber(Visualizable* visualizable) {
	this->subscribers.push_back(visualizable);
}

sf::RenderWindow* Visualizer::getRenderWindow() {
	return this->window;
}