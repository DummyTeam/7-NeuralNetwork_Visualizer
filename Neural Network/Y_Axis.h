#pragma once
#include "Axis.h"

class Y_Axis : public Axis
{
public:
	Y_Axis();
	void setPosition(sf::Vector2f pos);
	void setRange(double value);
private:
	double maxY;
};
