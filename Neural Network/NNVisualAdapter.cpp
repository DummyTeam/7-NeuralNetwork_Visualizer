#include "NNVisualAdapter.h"


NNVisualAdapter::NNVisualAdapter(NeuralNetwork* nn)
{
	this->nn = nn;
	this->init();
	this->arrangeVisually();
}

void NNVisualAdapter::init() {
	for (size_t i = 0; i < nn->getNumberOfLayers(); i++) // iterating layers
	{
		VisualLayer* visualLayer = new VisualLayer();

		for (size_t j = 0; j < (nn->getLayers())[i]->getSize(); j++) // iterating neurons
		{
			VisualNeuron* visualNeuron = new VisualNeuron((nn->getLayers())[i]->getNeurons().at(j)); // creating visual neuron
			visualLayer->addVisualNeurons(visualNeuron);

			if (i != 0)
				for (size_t z = 0; z < (((nn->getLayers())[i])->getNeurons()).at(j)->getInconmingWeights().size(); z++) // iterating weights
				{
					Weight* weight = (((nn->getLayers())[i])->getNeurons()).at(j)->getInconmingWeights().at(z);

					VisualWeight* visualWeight = new VisualWeight(
						weight,
						this->visualLayers[i - 1]->getVisualNeurons()[z],
						visualNeuron
					);

					this->visualWeights.push_back(visualWeight);
				}
		}
		this->visualLayers.push_back(visualLayer);
	}
}

void NNVisualAdapter::arrangeVisually() {
	for (auto& objs : this->visualLayers) {
		objs->arrangeVisually(this->nn->getMaxNumberOfNeurons(), (&objs - &(this->visualLayers[0])), this->visualLayers.size());
	}

	for (auto& objs : this->visualWeights) {
		objs->arrangeVisually();
	}

	this->drawableObjects.insert(this->drawableObjects.end(), this->visualWeights.begin(), this->visualWeights.end());
	this->drawableObjects.insert(this->drawableObjects.end(), this->visualLayers.begin(), this->visualLayers.end());
}

void NNVisualAdapter::draw(sf::RenderWindow* window) {
	for (auto& objs : this->drawableObjects) {
		objs->draw(window);
	}
}
