#pragma once
#include "Visualizable.h"

class Axis : public Visualizable
{
public:
	Axis();

private:
	sf::Vertex line[2];
};
