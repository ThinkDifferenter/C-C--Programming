#include "Head.h"

//产生n维的随机数
void a_Random(float gs[], int lengh)
{
	for (int i = 0; i < lengh; i++)
	{
		gs[i] = Gaussrand();
	}
}

float Gaussrand()
{
	float x = 0;
	int i;
	for (i = 0; i < NSUM; i++)
	{
		x += (float)rand() / RAND_MAX;
	}

	x -= NSUM / 2.0;
	x /= sqrt(NSUM / 12.0);

	return x;
}


