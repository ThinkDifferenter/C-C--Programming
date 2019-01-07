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

	//均值方差
	float mea = 0.0;
	float var = 0.0;

	//文件读取与写入 
	char filename_in[1024] = "D:\\高维向量匹配\\New_data\\vector_from_base.fea";
	FILE * fp_data = fopen(filename_in, "rb");

	//缓冲区变量-读入每个向量-明文 
	float buf[1025];

	//判断文件是否打开 
	if (fp_data == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//数据读入并处理 
	while (cnt<100) // 文件结束条件：!feof(fp_data)
	{
		cnt++;

		//缓存初始化 
		memset(buf, 0, sizeof(buf));

		//读取确认集中一个向量
		fread(buf, sizeof(float), 1025, fp_data);

		//向量编号记录
		printf("第%d个向量:ID=%.0f\t", cnt ,buf[0]);

		//计算均值
		mea = Mean(buf);

		//计算方差
		var = Variance(buf);

		//输出均值和方差
		printf("%f\t%f\n", mea, var);

	}

	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);

	//文件关闭 
	fclose(fp_data);

	getchar();

	return 0;
}