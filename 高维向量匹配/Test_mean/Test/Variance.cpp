#include "head.h"

float Variance(float arr[1025])
{
	float x, sum = 0.0, avg, powsum = 0.0;
	float var;
	int i;
	for (i = 1; i<1025 ; i++) 
	{
		sum += arr[i];
	}

	avg = sum / 1024;
	sum = 0.0;

	for (i = 1; i<1025; i++)
	{
		sum += pow((arr[i]-avg),2.0);
	}
	
	var = sum / 1024;
	return sqrt(var);
}