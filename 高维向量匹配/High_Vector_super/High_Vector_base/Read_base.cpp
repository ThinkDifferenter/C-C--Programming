#include "Head.h"

void Reader_base()
{
	//目标文件名
	char * filename_in = "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file_super\\91.data";
	FILE * fp_in = fopen(filename_in, "rb");

	//计数变量
	int cnt = 0;

	float id[1];
	double norm[1];

	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	while (!feof(fp_in))
	{
		fread(id, sizeof(float), 1, fp_in);
		fread(norm, sizeof(double), 1, fp_in);

		printf("\n========第%d个向量: ID=%.0f\t范数: Norm=%f=========\n", ++cnt, id, norm);
	}

	fclose(fp_in);
	getchar();
}