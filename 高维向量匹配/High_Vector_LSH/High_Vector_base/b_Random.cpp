#include "Head.h"

//产生一个指定区间的随机数
float b_Random(int min,int max)
{
	float R = 0.0;
	R = rand() % (max - min) + min;

	return R;
}