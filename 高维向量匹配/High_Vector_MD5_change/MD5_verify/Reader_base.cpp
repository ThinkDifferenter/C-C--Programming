#include "Head.h"

void Reader_base()
{
	char * filename_in = "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file_base\\69_94.data"; 
	FILE * fp_in = fopen(filename_in, "rb");

	int i = 0;
	int cnt = 0;
	unsigned char T_buf[20];

	//向量压缩后数据存储 
	int *compress1;
	int *compress2;

	//
	int *id;

	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}
	while (!feof(fp_in))
	{
		memset(T_buf, 0, sizeof(T_buf));

		fread(T_buf, sizeof(char), 20, fp_in);

		id = (int *)T_buf;

		//密文数据输出 
		printf("第%d个向量编号为:%d\n", ++cnt, *id);

		//for (i = 0; i<16; i++)
		//{
		//	printf("%02x", T_buf[i+4]);
		//}

		//密文数据处理
		compress1 = (int *)(T_buf + 4);
		compress2 = (int *)(T_buf + 8);

		//压缩信息输出
		printf("%d\t", *compress1);
		printf("%d\n", *compress2);
	}

	fclose(fp_in);
}