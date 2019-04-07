#include "MainWindow.h"

MainWindow::MainWindow()
{
	this->viewThread = new sf::Thread(&MainWindow::drawNetwork, this);
}

void  MainWindow::startWindow()
{
	this->viewThread->launch();
}

void MainWindow::drawNetwork() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Neural Network Visualizer", sf::Style::Default, settings);

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

		for (auto& elem : this->adapters) {
			elem->draw(this->window);
		}

		window->display();
	}
}

double MainWindow::getLayerVerticalOffset(int neuronCount) {
	return (maxNeuronsInALayer - neuronCount) * (neuronDiameter + distanceBetweenLayers) / 2.0;
}

void MainWindow::addAdapter(Visualizable* visualizable) {
	this->adapters.push_back(visualizable);
}

sf::RenderWindow* MainWindow::getRenderWindow() {
	return this->window;
}