#include "head.h"

float Mean(float arr[1025])
{
	float mea=0.0;
	float sum=0.0;
	int i;
	for (i = 1; i < 1025 ; i++)
	{
		sum += arr[i];
	}
	mea = sum / 1024;
	return mea;
}