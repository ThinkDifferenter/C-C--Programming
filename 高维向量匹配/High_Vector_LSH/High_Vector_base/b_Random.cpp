#include "Head.h"

//����һ��ָ������������
float b_Random(int min,int max)
{
	float R = 0.0;
	R = rand() % (max - min) + min;

	return R;
}