#pragma once

#include <vector>
#include "VisualWeight.h"

class VisualNeuron : public VisualObject
{
public:
	static double radius() { return 20.0; };

	VisualNeuron(Neuron*);
	
	sf::Text* getText();
	sf::CircleShape* getShape();
	void draw(sf::RenderWindow*);
	sf::Vector2f getCenterPoint();
	const sf::Vector2f& getInitPoint();

private:
	Neuron* neuronPointer;

	std::vector<VisualWeight*> incomingVisualWeights;
	std::vector<VisualWeight*> outgoingVisualWeights;

	sf::CircleShape* shape;
	sf::Text* text;
	sf::Font* font;

	float shapeWidth;
	float shapeHeight;
};
