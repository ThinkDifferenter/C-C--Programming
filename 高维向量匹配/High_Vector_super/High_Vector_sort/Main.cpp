#include "head.h"

//对每个索引文件中的向量按照模的大小排序
int main()
{
	//计数
	int cnt = 0;
	int i = 0;
	int j = 0;
	int cnt = 0;
	unsigned char min_buf[4108];
	int min_index = 0;
	double min = BIG_NUM;
	double *tmp = NULL;

	//向量数据存储 ID+模+向量
	unsigned char buf[4108];

	//排序结果文件参数 
	char filename_sort[1024];
	FILE * fp_sort[1000];

	//排序文件建立-1000个文件 
	for (i = 0; i<1000; i++)
	{
		sprintf(filename_sort, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file_super_sort\\%d.data", i);
		fp_sort[i] = fopen(filename_sort, "wb+");
		fclose(fp_sort[i]);
	}

	//索引数据文件参数 
	char filename_index[1024] = "";
	FILE * fp_index;

	//排序目标文件
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//打开一个索引文件进行排序
	for (i = 0; i<=1000; i++)
	{
		//打开索引文件
		sprintf(filename_index, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file_super\\%d.data", i);
		fp_index = fopen(filename_index, "rb");

		//打开对应排序文件
		sprintf(filename_tar, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file_super_sort\\%d.data", i);
		fp_tar = fopen(filename_tar, "wb");

		//获取文件大小
		fseek(fp_index, 0L, SEEK_END);
		int size = ftell(fp_index);
		size = size / 4108;
		fseek(fp_index, 0L, SEEK_SET);

		for(i=0;i<size;i++)
		{
			//对这个索引文件排序
			for (j = 0; j<size; j++)
			{
				//初始化内存
				memset(buf, 0, sizeof(buf));
				fread(buf, sizeof(unsigned char), 4108, fp_index);

				tmp = (double *)(fp_index + 4);

				if (*tmp<min)
				{
					min = *tmp;

					//for (j = 0; j < 4018; j++)
					//{
					//	min_buf[j] = buf[j];
					//}
					min_index = cnt;
				}

				cnt++;
			}

			//将索引文件中文件定位到最小下标上并读入一条记录
			fseek(fp_index, min_index, 0);
			fread(min_buf, sizeof(unsigned char), 4108, fp_index);

			//写入文件 
			fwrite(min_buf, sizeof(unsigned char), 4108, fp_tar);

			//修改数据
			tmp = (double *)(fp_index + 4);
			*tmp = BIG_NUM;

			//将索引文件中文件定位到最小下标上并写入文件
			fseek(fp_index, min_index, 0);
			fwrite(min_buf, sizeof(unsigned char), 4108, fp_index);

			//重置标识
			min = BIG_NUM;
			tmp = NULL;
			memset(min_buf, 0, sizeof(min_buf));

			//文件重定位
			fseek(fp_index, 0, 0);
		}

		
		fclose(fp_index);
		fclose(fp_tar);
	}

	return 0;
}