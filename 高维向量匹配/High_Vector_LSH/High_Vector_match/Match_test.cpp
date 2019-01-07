#include "Head.h"

void Match_test()
{
	//计数变量       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//id
	float *id;

	//H_1和H-2
	float *H_1;
	float *H_2;

	//局部敏感哈希
	float H[K];

	//文件读取与写入 
	char filename_in[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\verify_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//目标文件名 
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

	

	//读取数据集并处理 
	while (cnt<20) // 文件结束条件：!feof(fp_in)
	{
		cnt++;

		//缓存初始化 
		memset(buf, 0, sizeof(buf));

		//读取一个向量
		fread(buf, sizeof(float), 1025, fp_in);

		//取id
		id = (float *)buf;
		printf("第%d个匹配向量:\n", cnt);
		printf("Orign_id=%.0f\t", *id);

		//生成局部敏感哈希值
		LSH(buf + 1, H);

		//拿出目标文件中每条记录出来与当前确认向量匹配
		float T_id=0.0;
		float T_buf[K + 1];
		float distance = 0.0;
		float O_H = 0.0;
		float M_H = 0.0;
		float min_d = 1000000;


		//查找最小距离
		while (!feof(fp_tar))
		{
			memset(T_buf, 0, sizeof(T_buf));
			fread(T_buf, sizeof(float), K+1, fp_tar);

			//计算距离
			//distance = T_buf[1] - H[0];
			distance = O_distance(H, T_buf + 1);
			
			//printf("%f\n", distance);
			//判断最小距离
			if (distance < min_d)
			{
				//最小距离更新
				min_d = distance;

				//ID记录
				T_id = T_buf[0];

				//原始哈希值
				O_H = H[0];

				//匹配哈希值
				M_H = T_buf[1];
				
			}
		}

		printf("Match_id=%.0f\n", T_id);
		printf("Orign H=%f\tMatch H=%f\n", O_H, M_H);
		printf("The distance is %f\n\n", min_d);

		fseek(fp_tar, 0, 0);
	}

	//文件关闭 
	fclose(fp_in);
	fclose(fp_tar);

}

