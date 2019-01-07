#include "Head.h"

void Match()
{
	//MD5初始化
	MD5_CTX md5;
	MD5Init(&md5);

	//计数变量       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//压缩向量取余
	int x = 0;
	int y = 0;

	//文件读取与写入 
	char filename_in[1024] = "D:\\高维向量匹配\\hdss_cnsoft2018\\verify_vector.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//目标文件所在文件 
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//缓冲区变量-读入每个向量-明文 
	float buf[1025];

	//密文数据临时缓冲区 - 第一位数据为向量的id 
	unsigned char decrypt[16];

	//向量压缩后数据存储
	int *compress1;
	int *compress2;

	//向量id数据存储 
	int *id;

	//判断文件是否打开 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//数据读入并处理 
	while (cnt<100) // 文件结束条件：!feof(fp_in)
	{
		cnt++;

		//缓存初始化 
		memset(buf, 0, sizeof(buf));

		//读取确认集中一个向量
		fread(buf, sizeof(float), 1025, fp_in);

		//向量编号记录
		id = (int *)buf;
		printf("ID=%.0f\n", *id);

		//向量数据加密 
		MD5Update(&md5, (unsigned char*)buf + 4, 1024 * 4);

		//密文数据存储 
		MD5Final(&md5, decrypt);

		//密文数据处理
		compress1 = (int *)decrypt;
		compress2 = (int *)(decrypt + 4);

		//printf("compress1=%d\n", *compress1);
		//printf("compress2=%d\n", *compress2);

		//取余判断向量在哪个文件中 
		x = abs((*compress1) % 100);
		y = abs((*compress2) % 100);

		//printf("x=%d\n", x);
		//printf("y=%d\n", y);

		//打开目标文件
		sprintf(filename_tar, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file\\%d_%d.data", x, y);
		fp_tar = fopen(filename_tar, "rb");

		//拿出目标文件中每条记录出来与当前确认向量匹配
		int *T_id;
		unsigned char T_decrypt[16];
		int *T_compress1;
		int *T_compress2;
		int flag = 0;

		while (!feof(fp_tar))
		{
			memset(T_id, 0, sizeof(T_id));
			memset(T_decrypt, 0, sizeof(T_decrypt));

			fread(T_id, sizeof(int), 1, fp_tar);//读ID
			fread(T_decrypt, sizeof(char), 16, fp_tar); //读md5码 

			T_compress1 = (int *)T_decrypt;
			T_compress2 = (int *)(T_decrypt + 4);

			//printf("%.6f\t",T_id[0]);

			if (*T_id == *id)
			{
				flag = 1;
				printf("第%d个匹配向量的id为:%.6f\n", cnt, *T_id);
				break;
			}
		}
		if (flag == 0)
		{
			printf("第%d个匹配向量没有找到!\n", cnt);
		}

		//关闭目标文件 
		fclose(fp_tar);
	}

	//文件关闭 
	fclose(fp_in);
}