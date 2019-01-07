#include "Head.h"

void k_Random()
{
	int i = 0;
	int a[K];
	int b[K];
	
	for (i = 0; i < K; i++)
	{
		a[i] = rand() % 100 + 1;
		b[i] = rand() % 100 + 1;
		//printf("a=%d b=%d\n", a[i],b[i]);
	}

	char filename1[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\Test\\K_random_a.data";
	FILE * fp1 = fopen(filename1, "wb+");

	char filename2[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\Test\\K_random_b.data";
	FILE * fp2 = fopen(filename2, "wb+");

	//保存高斯随机向量到文件
	fwrite(a, sizeof(int), K , fp1);  //a
	fwrite(b, sizeof(int), K , fp2);  //b

	fclose(fp1);
	fclose(fp2);
}