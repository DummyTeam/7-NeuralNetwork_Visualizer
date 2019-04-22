#include "VisualLayer.h"

VisualLayer::VisualLayer()
{

}

void VisualLayer::addVisualNeurons(VisualNeuron* vNeuron) {
	this->visualNeurons.push_back(vNeuron);
}

const std::vector<VisualNeuron*>& VisualLayer::getVisualNeurons() {
	return this->visualNeurons;
}

void VisualLayer::draw(sf::RenderWindow* window) {
	for (auto& vNeuron : this->visualNeurons) {
		vNeuron->draw(window);
	}
}

void VisualLayer::arrangeVisually(int maxNeurons, int layerIndex, int numberOfLayers, int screenWidth, int screenHeight) {
	float l = screenWidth;
	float h = screenHeight;

	float w = 100.0f;
	float g = 15.0f;
	float nd = VisualNeuron::radius();

	float p = 30.0f;
	float bh = (h - 2 * p - 2 * nd * maxNeurons - g * (maxNeurons - 1)) / 2.0;
	float bl = (l - 2 * p - 2 * nd * numberOfLayers - w * (numberOfLayers - 1)) / 2.0;
	
	float layerOffset = ((maxNeurons - this->visualNeurons.size()) * nd * 2 + (maxNeurons - this->visualNeurons.size()) * g) / 2.0;

	for (size_t i = 0; i < this->visualNeurons.size(); i++) {
		// the condition means whether it is the first layer neuron
		this->visualNeurons[i]->getShape()->setPosition(nd * 1.5 + p + bl + layerIndex * (nd + w), p + bh + layerOffset + i * (nd * 2 + g));
	}
}