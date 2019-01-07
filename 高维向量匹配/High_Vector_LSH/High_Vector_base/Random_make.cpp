#include "Head.h"

//产生K组a、b 参数

void Random_make()
{
	int i = 0;

	float a[1024];
	float b[1];

	char filename_Gauus[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\Gauss.data";
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
		fwrite(a, sizeof(float), 1024, fp_Gauss);  //写a
		fwrite(b, sizeof(float), 1, fp_Gauss);     //写b
		
	}

	fclose(fp_Gauss);
}