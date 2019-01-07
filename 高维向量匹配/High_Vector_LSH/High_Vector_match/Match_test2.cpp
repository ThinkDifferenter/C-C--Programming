#include "Head.h"

void Match_test2()
{
	//计数变量       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//确认集向量ID
	float *id;

	//局部敏感哈希
	float H[K];

	//文件读取与写入 
	char filename_in[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\verify_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//目标文件所在文件 
	char filename_tar[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\H_compress.data";
	FILE * fp_tar = fopen(filename_tar, "rb");


	//缓冲区变量-读入每个向量
	float buf[1025];

	//判断文件是否打开 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//数据读入并处理 
	while (cnt<50) 
	{
		cnt++;

		//缓存初始化 
		memset(buf, 0, sizeof(buf));

		//读取确认集中一个向量
		fread(buf, sizeof(float), 1025, fp_in);

		//取ID
		id = (float *)buf;
		printf("第%d个匹配向量:\n", cnt);
		printf("Orign_id=%.0f\t", *id);

		//生成局部敏感哈希值
		LSH(buf + 1,H);

		//拿出目标文件中每条记录出来与当前确认向量匹配
		float *T_id;
		float T_buf[K + 1];
		float dis;

		//直接用ID匹配查找
		while (!feof(fp_tar))
		{
			memset(T_buf, 0, sizeof(T_buf));

			fread(T_buf, sizeof(float), K+1 , fp_tar); 

			T_id = (float *)T_buf;

			if (*T_id == *id)
			{
				printf("Match_id=%.0f\n", *T_id);
				printf("Orign H=%f\tMatch H=%f\n", H[0], T_buf[1]);

				dis = O_distance(H, T_buf + 1);
				printf("The distance is %f\n\n", dis);
				
				fseek(fp_tar, 0, 0);
				break;
			}
		}

		fseek(fp_tar, 0, 0);

	}

	//文件关闭 
	fclose(fp_in);
	fclose(fp_tar);
	
}