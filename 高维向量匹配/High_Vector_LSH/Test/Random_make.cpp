#include "Head.h"

void Random_make()
{
	int i = 0;

	float a[1024];
	float b[1];

	char filename_Gauus[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\Test\\Gauss.data";
	FILE * fp_Gauss = fopen(filename_Gauus, "wb+");

	for (i = 0; i < K; i++)
	{ 
		//缓存初始化 
		memset(a, 0, sizeof(a));

		//生成高斯随机向量
		a_Random(a, 1024);
		
		//生成指定区间随机数
		b[0] = b_Random(0, W);
		
		//保存高斯随机向量到文件
		fwrite(a, sizeof(float), 1024, fp_Gauss);  //a
		fwrite(b, sizeof(float), 1, fp_Gauss);     //b
		
	}

	fclose(fp_Gauss);
}