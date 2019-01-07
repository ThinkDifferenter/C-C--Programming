#include "Head.h"

float O_distance(float *arr1, float *arr2)
{
	int i = 0;
	float sum = 0.;
	float dis = 0.0;
	for (i = 0; i < K; i++)
	{
		sum += pow(arr1[i]-arr2[i],2);
	}
	dis = sqrt(sum);

	return dis;
}