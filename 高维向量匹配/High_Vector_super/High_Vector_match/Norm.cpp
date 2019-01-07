#include "Head.h"

double Norm(float * arr)
{
	double result = 0.0;
	int i = 0;
	for (i = 1; i < 1025; i++)
	{
		result += pow(arr[i], 2);
	}
	result = sqrt(result);
	return result;
}