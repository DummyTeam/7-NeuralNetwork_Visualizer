#include "MainWindow.h"

Window::Window()
{
	this->viewThread = new sf::Thread(&Window::drawNetwork, this);
}

void  Window::startWindow()
{
	this->viewThread->launch();
}

void Window::drawNetwork() {

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

		window->clear(sf::Color::White);

		for (auto& elem : this->adapters) {
			elem->draw(this->window);
		}

		window->display();
	}
}

void Window::addAdapter(Visualizable* visualizable) {
	this->adapters.push_back(visualizable);
}

sf::RenderWindow* Window::getRenderWindow() {
	return this->window;
}