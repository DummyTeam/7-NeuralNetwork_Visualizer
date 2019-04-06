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

void VisualLayer::arrangeVisually(int maxNeurons, int layerIndex) {
	float w = 80.0f;
	float g = 10.0f;
	float nd = 20.0f;
	float layerOffset = ((maxNeurons - this->visualNeurons.size()) * nd * 2 + (maxNeurons - this->visualNeurons.size()) * g) / 2.0;

	for (int i = 0; i < this->visualNeurons.size(); i++) {
		// the condition means whether it is the first layer neuron
		this->visualNeurons[i]->getShape()->setPosition(layerIndex*(nd + w), layerOffset + i * (nd * 2 + g));
	}
}