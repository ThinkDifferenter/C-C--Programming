#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h> 
#include <time.h> 

#define NSUM 25
#define W 4
#define K 12
#define C 429496729
#define T 100

void a_Random(float gs[], int lengh);
float Gaussrand();
float b_Random(int min, int max);

void Process1();
void Reader_base();

void LSH(float *v, float H[K]);

void Random_make();
void k_Random();

float Hash_1(float H[K]);
float Hash_2(float H[K]);


void LSH(float *v,float H[K])
{
	//计数变量
	int i = 0;
	int j = 0;
	
	//哈希数据记录
	float Sum = 0.0;

	//参数存储
	float a[1024];
	float b[1];

	//打开参数文件
	char filename_Gauus[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\Gauss.data";
	FILE * fp_Gauss = fopen(filename_Gauus, "rb");

	for (i = 0; i < K; i++)
	{
		//读取参数a,b
		fread(a, sizeof(float), 1024, fp_Gauss);  //a
		fread(b, sizeof(float), 1, fp_Gauss);     //b

		for (j = 0; j < 1024; j++)
		{
			Sum += a[i] * v[i];
		}

		H[i] = (Sum + b[0]) / W;

		Sum = 0.0;
	}

	fclose(fp_Gauss);
}

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
	char filename_tar[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\H_index.data";
	FILE * fp_tar = fopen(filename_tar, "wb+");

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
		
		//取id
		id = (float *)buf;
		
		//生成局部敏感哈希值
		LSH(buf + 4,H);

		/*
		//生成H_1和H_2
		H_1 = Hash_1(H);
		H_2 = Hash_2(H);

		//printf("%f\t%f\n", H_1, H_2);
		
		//printf("%f\n", *id);
		for (i = 0; i < K; i++)
		{
			printf("%f\t", H[i]);
		}
		printf("\n\n");
		*/

		//写入对应文件
		fwrite(id, sizeof(float), 1, fp_tar);  //写id
		fwrite(H, sizeof(float), K , fp_tar);  //写向量H

	}

	//文件关闭 
	fclose(fp_in);
	fclose(fp_tar);

}

int main(int argc, char *argv[])
{
	srand(time(NULL));
	int begintime;
	int endtime;
	begintime = clock();

	//Random_make();
	//k_Random();
	Process1();

	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);
	system("pause");

	return 0;
}