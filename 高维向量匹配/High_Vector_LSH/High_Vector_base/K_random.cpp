#include "Head.h"

void K_random()
{
	char filename_a[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\K_random_a.data";
	FILE * fp_a = fopen(filename_a, "wb+");

	char filename_b[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\K_random_b.data";
	FILE * fp_b = fopen(filename_b, "wb+");


	float a[K];
	float b[K];

	int i = 0;
	
	for (i = 0; i < K; i++)
	{
		a[i] = (int)rand() % 100;
		b[i] = (int)rand() % 100;
	}

	fwrite(a, sizeof(int), K, fp_a);  //дa
	fwrite(b, sizeof(int), K, fp_b);  //дb

	fclose(fp_a);
	fclose(fp_b);
}