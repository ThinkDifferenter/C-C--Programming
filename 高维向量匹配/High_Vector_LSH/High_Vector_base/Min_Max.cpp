#include "Head.h"

void Min_Max()
{
	//计数变量       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//最大最小值
	float min = 1000000000.0;
	float max = -1000000000.0;

	//局部敏感哈希
	float H = 0.0;

	//生成高斯随机向量
	float a[1024];
	float tmp[1];
	
	//读取事先保存的随机数
	char filename_Gauus[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\Gauss.data";
	FILE * fp_Gauss = fopen(filename_Gauus, "rb");
	fread(a, sizeof(float), 1024, fp_Gauss);  //读随机向量a
	fread(tmp, sizeof(float), 1, fp_Gauss);   //读b
	float b = tmp[0];
	
	printf("%f\t", a[1023]);
	printf("%f\n", b);

	fclose(fp_Gauss);


	//文件读取与写入 
	char filename_in[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\base_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//缓冲区变量-读入每个向量
	float buf[1025];

	//判断文件是否打开 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//读取数据集并处理 
	while (cnt<10) // 文件结束条件：!feof(fp_in)
	{
		cnt++;

		//缓存初始化 
		memset(buf, 0, sizeof(buf));

		//读取一个向量
		fread(buf, sizeof(float), 1025, fp_in);

		//生成局部敏感哈希值
		H = LSH(a, buf + 4, b);

		printf("%f\n", H);

		if (min > H)
		{
			min = H;
		}

		if (max < H)
		{
			max = H;
		}

	}

	printf("min=%f\t max=%f\n", min, max);

	//文件关闭 
	fclose(fp_in);

}