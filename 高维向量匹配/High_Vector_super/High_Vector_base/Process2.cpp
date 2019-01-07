#include "Head.h"

//将计算出模的向量排序后存储在一个索引文件中-需对文件中数据进行排序
//数据保存：ID + 模 + 向量 4+8+1024*4

void Process2()
{

	//计数变量       
	int i = 0;
	int tmp = 0;
	int cnt = 0;

	//文件读取与写入 
	char filename_in[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\base_vectors.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//目标文件名 
	char filename_tar[1024] = "";
	FILE * fp_tar = fopen(filename_in, "wb+");;

	//缓冲区变量-读入每个向量
	float buf[1025];
	double norm[1];

	//判断文件是否打开 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//数据读入并处理 
	while (cnt<1000000) // 文件结束条件：!feof(fp_in)
	{
		cnt++;

		//缓存初始化 
		memset(buf, 0, sizeof(buf));
		norm[0] = 0.0;
		tmp = 0;

		//读取一个向量
		fread(buf, sizeof(float), 1025, fp_in);

		//计算距离判断向量在哪个文件
		norm[0] = Norm(buf);
		tmp = (int)((norm[0] - 17.273566) / 0.0024491);

		//通过范数判断向量所属文件夹
		fwrite(buf, sizeof(float), 1, fp_tar);  //写ID 
		fwrite(norm, sizeof(double), 1, fp_tar); //写范数

		
	}

	//文件关闭 
	fclose(fp_in);
	fclose(fp_tar);

}