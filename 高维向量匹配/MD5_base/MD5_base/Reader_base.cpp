#include "Head.h"

void Reader_base()
{
	//目标文件名
	char * filename_in = "65_25.data";
	FILE * fp_in = fopen(filename_in, "rb");

	//计数变量
	int i = 0;
	int cnt = 0;
	float id[1];
	unsigned char decrypt[16];

	//向量压缩后数据存储 
	int *compress1;
	int *compress2;

	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	while (!feof(fp_in))
	{
		memset(decrypt, 0, sizeof(decrypt));

		fread(id, sizeof(float), 1, fp_in);
		fread(decrypt, sizeof(char), 16, fp_in);

		//密文数据输出 
		printf("\n\n========第%d个向量编号为:%.0f=========\n", ++cnt, id[0]);
		for (i = 0; i<16; i++)
		{
			printf("%02x", decrypt[i]);
		}

		//密文数据处理
		compress1 = (int *)decrypt;
		compress2 = (int *)(decrypt + 4);

		//压缩信息输出
		printf("\n%d\t", *compress1);
		printf("%d", *compress2);
	}

	fclose(fp_in);
}