#include "NNGraphAdapter.h"
#include "GraphRangeStyle.h"

NNGraphAdapter::NNGraphAdapter(NeuralNetwork* nn, GraphRangeStyle* graphRangeStyle)
{
	this->nn = nn;
	this->graph = new Graph(nn->getLearningMethod()->getCostHistory(), graphRangeStyle);
	this->screenMessage = new ScreenMessage();
}

void NNGraphAdapter::init(sf::RenderWindow* renderWindow) {
	this->renderWindow = renderWindow;

	int width = (renderWindow->getSize().x - this->graph->getSize().x) / 2.0;
	int height = (renderWindow->getSize().y - this->graph->getSize().y) / 2.0;

	this->graph->setPosition(sf::Vector2f(width, height));
}

void NNGraphAdapter::draw() {
	this->graph->draw(this->renderWindow);

	this->screenMessage->setMessage(
		"Stage: " + this->nn->getCurrentStage() + "\n" +
		"Cost: " + std::to_string(this->nn->getLearningMethod()->getCurrentCost())
	);
	this->screenMessage->draw(this->renderWindow);
}
