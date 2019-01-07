#include "Head.h"

void LSH(float *v,float H[K])
{
	//计数变量
	int i = 0;
	int j = 0;
	
	//哈希数据记录
	float Sum = 0.0;

	//参数存储
	float a[1024];
	float b[1];

	//打开参数文件
	char filename_Gauus[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\Test\\Gauss.data";
	FILE * fp_Gauss = fopen(filename_Gauus, "rb");

	//for (int i = 0; i < 10; i++)
	//	printf("%f  ", v[i]);


	for (i = 0; i < K; i++)
	{
		//读取参数a,b
		fread(a, sizeof(float), 1024, fp_Gauss);  //a
		fread(b, sizeof(float), 1, fp_Gauss);     //b



		for (j = 0; j < 1024; j++)
		{
			
			Sum += a[j] * v[j];
		}
		//printf("%f ", b[0]);
		H[i] = (Sum + b[0])/W;
		H[i] = floor(H[i]);
		//printf("%f ",floor(H[i]));
		Sum = 0.0;
	}

	fclose(fp_Gauss);
}