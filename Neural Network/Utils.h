#pragma once
#include"Core.h"
class Utils
{
public:
	// from 0 to 99
	static double randomNumber()
	{
		return (rand() % 10000) / 100.0;
	}

	static double randomNumber(double from, double to)
	{
		return 	(rand() % ((int)(to - from) * 100)) / 100.0 + from;
	}

	static int randomNumberInt(int from, int to)
	{
		return 	rand() % (to - from + 1) + from;
	}
};
