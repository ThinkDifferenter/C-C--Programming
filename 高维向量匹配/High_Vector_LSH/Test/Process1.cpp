#include "Head.h"

void Process1()
{
	//计数变量       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//id
	float *id;

	//H_1和H-2
	float H_1 = 0.0;
	float H_2 = 0.0;

	//局部敏感哈希
	float H[K];

	//文件读取与写入 
	char filename_in[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\base_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//目标文件名 
	//char filename_tar[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\verify_vector_new.fea";
	//FILE * fp_tar = fopen(filename_tar, "rb");

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
		
		//取id
		id = (float *)buf;
	
		//生成局部敏感哈希值
		LSH(buf + 1,H);
		
		H_1 = Hash_1(H);
		H_2 = Hash_2(H);

		printf("%f\t%f\n", H_1, H_2);
		
		//float s = 0;
		//printf("id = %f\n", *id);
		//for (i = 0; i < K; i++)
		//{
		//	printf("%f\t", H[i]);
		//}
		//printf("\n\n");
		

		//写入对应文件
		//fwrite(id, sizeof(float), 1, fp_tar);  //写id
		//fwrite(H, sizeof(float), K , fp_tar);  //写向量H

	}

	//文件关闭 
	fclose(fp_in);
	//fclose(fp_tar);

}