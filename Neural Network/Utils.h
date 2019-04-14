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
		return 	(rand() % (int)((to - from) * 10000.0)) / 10000.0 + from;
	}

	static int randomNumberInt(int from, int to)
	{
		return 	rand() % (to - from + 1) + from;
	}

	static double map(double ratio1_1, double ratio1_2, double ratio2_1)
	{
		return (ratio1_2 * ratio2_1) / ratio1_1 * 1.0;
	}
};
