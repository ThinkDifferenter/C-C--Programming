#include "Head.h"

void Process()
{
	//计数变量       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//取余
	int Remainder = 0;

	//局部敏感哈希
	float H = 0.0;



	//哈希文件参数 
	char filename[1024] = "";
	FILE * fp[1000];

	//哈希文件建立 - 1000 
	for (i = 0; i<1000; i++)
	{
		sprintf(filename, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file_LSH\\%d.data", i);
		fp[i] = fopen(filename, "wb+");
		fclose(fp[i]);
	}

	//目标文件名 
	char filename_tar[1024] = "";
	FILE * fp_tar;

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
	while (cnt<100) // 文件结束条件：!feof(fp_in)
	{
		cnt++;

		//缓存初始化 
		memset(buf, 0, sizeof(buf));

		//读取一个向量
		fread(buf, sizeof(float), 1025, fp_in);

		//生成局部敏感哈希值
		H = LSH(buf + 4);

		printf("%f\n", H);

		//取余 
		Remainder = abs((int)H % 1000);

		//打开目标文件
		sprintf(filename_tar, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file_LSH\\%d.data", Remainder);
		fp_tar = fopen(filename_tar, "ab");

		//写入对应文件
		fwrite(buf, sizeof(float), 1025, fp_tar);  //写向量

												   //关闭目标文件 
		fclose(fp_tar);
	}

	//文件关闭 
	fclose(fp_in);

}