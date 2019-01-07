#include "head.h"

int main(int argc, char *argv[])
{
	int begintime;
	int endtime;

	begintime = clock();

	//计数变量       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//打开确认集文件-文件读取与写入 
	char filename_ver[1024] = "D:\\高维向量匹配\\New_data\\verify_vector.fea";
	FILE * fp_ver = fopen(filename_ver, "rb");

	//打开数据集文件-文件读取与写入
	char filename_base[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\base_vectors.fea";
	FILE * fp_base = fopen(filename_base, "rb");

	//将查找到的向量存放到文件中
	char file[1024] = "D:\\高维向量匹配\\New_data\\vector_from_base.fea";
	FILE * fp_tar = fopen(file, "wb+");
	fclose(fp_tar);
	

	//确认集-缓冲区变量-读入每个向量 
	float buf_ver[1025];

	//数据集缓冲变量
	float buf_base[1025];

	//判断文件是否打开 
	if (fp_ver == NULL)
	{
		printf("Can not open %s!\n", filename_ver);
		exit(0);
	}

	if (fp_base == NULL)
	{
		printf("Can not open %s!\n", filename_base);
		exit(0);
	}

	//数据读入对比
	while (cnt<100) // 文件结束条件：!feof(fp_ver)
	{
		cnt++;

		//缓存初始化 
		memset(buf_ver, 0, sizeof(buf_ver));

		//读取确认集中一个向量
		fread(buf_ver, sizeof(float), 1025, fp_ver);

		//向量编号记录
		//printf("第%d个向量:ID=%.0f\t", cnt, buf[0]);
		
		while (1)
		{
			//缓存初始化 
			memset(buf_base, 0, sizeof(buf_base));

			//读取数据集中一个向量
			fread(buf_base, sizeof(float), 1025, fp_base);

			//对比
			if (buf_ver[0] == buf_base[0])
			{
				//打开目标文件
				fp_tar = fopen(file, "ab");

				//数据集向量保存
				fwrite(buf_base, sizeof(float), 1025 , fp_tar);
				
				//关闭目标文件
				fclose(fp_tar);

				//数据集文件指针重定位
				fseek(fp_base, 0 , SEEK_SET);

				break;
			}

		}

	}

	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);

	//文件关闭 
	fclose(fp_ver);
	fclose(fp_base);

	getchar();

	return 0;
}


/*	int fseek(FILE *stream, long offset, int fromwhere);

	第一个参数stream为文件指针

　　第二个参数offset为偏移量，正数表示正向偏移，负数表示负向偏移

　　第三个参数origin设定从文件的哪里开始偏移,可能取值为：SEEK_CUR、 SEEK_END 或 SEEK_SET

　　SEEK_SET： 文件开头

　　SEEK_CUR： 当前位置

　　SEEK_END： 文件结尾

  　其中SEEK_SET,SEEK_CUR和SEEK_END依次为0，1和2.
*/