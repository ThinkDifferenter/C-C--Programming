#include "Head.h"

float Hash_2(float H[K])
{
	int i = 0;
	int b[K];
	float Sum = 0.0;
	float H_2 = 0.0;
	
	//�򿪲����ļ�
	char filename[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\K_random_b.data";
	FILE * fp = fopen(filename, "rb");

	fread(b, sizeof(float), K, fp);  //b
	fclose(fp);

	for (i = 0; i < K; i++)
	{
		Sum += b[i] * H[i];
	}

	H_2 = (int)Sum % C;

	return H_2;
}