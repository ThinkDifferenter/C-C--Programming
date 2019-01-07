#include "Head.h"

void Reader_verify()
{
	char filename_in[1024] = "verify_vector.fea"; //id 2431229 65 25
	FILE * fp_in = fopen(filename_in, "rb");

	int i = 0;
	int cnt = 0;
	float buf[1025];

	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	while (cnt<100)
	{
		memset(buf, 0, sizeof(buf));
		fread(buf, sizeof(float), 1025, fp_in);

		//密文数据输出 
		printf("\n========第%d个向量编号为:%.0f=========\n", ++cnt, buf[0]);

	}
	fclose(fp_in);
}