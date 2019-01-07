#include "Head.h"

void Reader_verify()
{
	char filename_in[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\verify_vector.fea"; 
	FILE * fp_in = fopen(filename_in, "rb");

	int i = 0;
	int cnt = 0;
	float buf[1025];

	int *id;

	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	while (cnt<100)
	{
		memset(buf, 0, sizeof(buf));
		fread(buf, sizeof(float), 1025, fp_in);

		id = (int *)buf;

		//密文数据输出 
		printf("========第%d个向量编号为:%d=========\n", ++cnt, *id);

	}
	fclose(fp_in);

}