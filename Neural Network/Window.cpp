#include "Window.h"

Window::Window()
{
	init();
}

Window::Window(int screenWidth, int screenHeight)
{
	init();
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

Window::Window(sf::Vector2i screenDimensions, sf::Vector2i screenPosition, std::string windowTitle) {
	init();
	this->screenWidth = screenDimensions.x;
	this->screenHeight = screenDimensions.y;

	this->screenXPos = screenPosition.x;
	this->screenYPos = screenPosition.y;

	this->windowTitle = windowTitle;
}

void Window::init() {
	this->viewThread = new sf::Thread(&Window::drawNetwork, this);
	this->screenWidth = 800;
	this->screenHeight = 600;

	this->screenXPos = 100;
	this->screenYPos = 100;

	this->windowTitle = "Neural Network Visualizer";
}

void  Window::startWindow()
{
	this->viewThread->launch();
}

void Window::drawNetwork() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	this->window = new sf::RenderWindow(sf::VideoMode(this->screenWidth, this->screenHeight), this->windowTitle, sf::Style::Default, settings);
	this->window->setVerticalSyncEnabled(true);
	this->window->setPosition(sf::Vector2i(this->screenXPos, this->screenYPos));
	//this->window->setFramerateLimit(60);

	for (auto& elem : this->adapters) {
		elem->init(this->window);
	}

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
			elem->draw();
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