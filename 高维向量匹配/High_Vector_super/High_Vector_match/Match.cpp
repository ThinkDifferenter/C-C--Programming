#include "Head.h"

void Match()
{
	//计数变量       
	int i = 0;
	int j = 0;
	int tmp = 0;
	int cnt_v = 0;
	int cnt_i = 0;

	//缓冲区变量-读入每个向量 
	float buf[1025];
	float *V_id;
	double norm = 0.0;


	//打开确认集文件
	char filename_in[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\verify_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//目标文件参数 
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//匹配结果文件参数
	char filename_result[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\Result.fea";
	FILE * fp_result=fopen(filename_result, "wb+");;


	//判断确认文件是否打开 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//读入确认集向量并匹配 
	while (cnt_v<50) 
	{
		cnt_v++;

		//缓存初始化 
		memset(buf, 0, sizeof(buf));

		//读取确认集中一个向量
		fread(buf, sizeof(float), 1025, fp_in);

		//取出确认向量的id
		V_id = (float *)buf;
		printf("Orign_id = %.0f\n", *V_id);

		//取模
		norm = Norm(buf);
		tmp = (int)((norm - Min_norm) / Step);

		//打开查找目标文件
		sprintf(filename_tar, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file_super\\%d.data", tmp);
		fp_tar = fopen(filename_tar, "rb");

		//判断当前确认集向量的范数所在位置
		double Min_distance = 10000.0;
		double Od = 0.0;
		float T_buf[1025];
		float Min_buf[1025];
		int flag = 0;

		//开始查找
		while (!feof(fp_tar))
		{
			cnt_i++;

			//初始化缓冲
			memset(T_buf, 0, sizeof(T_buf));

			//读取索引文件向量
			fread(T_buf, sizeof(float), 1025 , fp_tar);
			
			//计算欧式距离判断
			Od = O_distance(buf, T_buf);
			
			//查找最小欧式距离
			if (Od < Min_distance)
			{
				Min_distance = Od;

				for (j = 0; j < 1025; j++)
				{
					Min_buf[j] = T_buf[j];
				}
			}

		}

		//距离最小的向量写入文件
		fwrite(Min_buf, sizeof(float), 1025, fp_result);
		float *T_id;
		T_id = (float *)Min_buf;
		printf("Match_id = %.0f\n\n", *T_id);

		fclose(fp_tar);
	}

	//文件关闭 
	fclose(fp_in);
	fclose(fp_result);

}