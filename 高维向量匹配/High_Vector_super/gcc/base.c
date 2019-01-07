#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h> 
#include <time.h> 
#include <Windows.h>

#define Min_norm 17.273566
#define Step 0.0024491

//===============================程序声明================================= 


double Norm(float * arr);
void Process1();
void Process2();
void Reader_base();


int main(int argc, char *argv[])
{
	int begintime;
	int endtime;
	begintime = clock();

	Process1();

	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);

	system("pause");

	return 0;
}

double Norm(float * arr)
{
	double result = 0.0;
	int i = 0;
	for (i = 1; i < 1025; i++)
	{
		result += pow(arr[i], 2);
	}
	result = sqrt(result);
	return result;
}


void Process1()
{
	//计数变量       
	int i = 0;
	int tmp = 0;
	int cnt = 0;

	//文件读取与写入 
	char filename_in[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\base_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//目标文件名 
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//索引数据文件参数 
	char filename[1024] = "";
	FILE * fp[1000];

	//压缩数据文件建立 - 1000个文件 
	for (i = 0; i<1000; i++)
	{
			sprintf(filename, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file_super\\%d.data", i);
			fp[i] = fopen(filename, "wb+");
			fclose(fp[i]);
	}

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
		tmp = (int)( (norm[0] - Min_norm) / Step);
		
		//打开目标文件
		sprintf(filename_tar, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file_super\\%d.data",tmp);
		fp_tar = fopen(filename_tar, "ab");

		//通过范数判断向量所属文件夹
		fwrite(buf, sizeof(float), 1, fp_tar);  //写ID 
		fwrite(norm, sizeof(double), 1, fp_tar); //写范数
		fwrite(buf+4, sizeof(float), 1024, fp_tar); //写向量

		//关闭目标文件 
		fclose(fp_tar);
	}

	//文件关闭 
	fclose(fp_in);
}