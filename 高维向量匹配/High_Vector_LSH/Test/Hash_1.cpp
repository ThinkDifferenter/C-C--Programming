#include "Head.h"

float Hash_1(float H[K])
{
	int i = 0;
	int a[K];
	float Sum = 0.0;
	float H_1 = 0.0;
	
	//�򿪲����ļ�
	char filename[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Test\\K_random_a.data";
	FILE * fp = fopen(filename, "rb");

	fread(a, sizeof(float), K, fp);  //a
	fclose(fp);

	for (i = 0; i < K; i++)
	{
		Sum += a[i] * H[i];
	}

	H_1 = ((int)Sum % C) % T;
	
	return H_1;
}