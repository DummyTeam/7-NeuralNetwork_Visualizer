#pragma once

#include "VisualNeuron.h"
#include <vector>

class VisualLayer : public VisualObject
{
public:
	VisualLayer();
	void addVisualNeurons(VisualNeuron*);
	const std::vector<VisualNeuron*>& getVisualNeurons();

	void draw(sf::RenderWindow* window);
	void arrangeVisually(int maxNeurons, int layerIndex, int numberOfLayer, int screenWidth, int screenHeight);

private:
	std::vector<VisualNeuron*> visualNeurons;
};

