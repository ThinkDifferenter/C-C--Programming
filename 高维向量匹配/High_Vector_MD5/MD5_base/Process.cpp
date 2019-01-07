#include "Head.h"

void Process()
{
	//md5初始化
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

	//目标文件名 
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//压缩数据文件参数 
	char filename[1024] = "";
	FILE * fp[100][100];

	//压缩数据文件建立 - 10000个文件 
	for (i = 0; i<100; i++)
	{
		for (j = 0; j<100; j++)
		{
			sprintf(filename, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file\\%d_%d.data", i, j);
			fp[i][j] = fopen(filename, "wb+");
			fclose(fp[i][j]);
		}
	}

	//缓冲区变量-读入每个向量-明文 
	float buf[1025];

	//密文数据临时缓冲区 
	unsigned char decrypt[16];

	//向量压缩后数据指针 
	int *compress1;
	int *compress2;

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

		//读取一个向量
		fread(buf, sizeof(float), 1025, fp_in);

		//向量数据加密 
		MD5Update(&md5, (unsigned char*)buf+4, 1024*4);

		//密文数据存储 
		MD5Final(&md5, decrypt);

		//密文数据输出 
		int *id=(int *)buf;
		printf("第%d个向量编号为:%d\n",cnt,*id);

		//for(i=0;i<16;i++)
		//{
		//	printf("%02x",decrypt[i]);		
		//}

		//密文数据处理
		compress1 = (int *)decrypt;
		compress2 = (int *)(decrypt + 4);

		//压缩信息输出
		printf("%d\t", *compress1); 
		printf("%d\n", *compress2); 

		//取余 
		x = abs((*compress1) % 100);
		y = abs((*compress2) % 100);

		//打开目标文件
		sprintf(filename_tar, "D:\\高维向量匹配\\hdss_cnsoft2018\\Index_file\\%d_%d.data", x, y);
		fp_tar = fopen(filename_tar, "ab");

		//通过压缩二维向量信息判断该向量的MD5该写入哪个文件
		fwrite(buf, sizeof(int), 1, fp_tar);  //写ID 
		fwrite(decrypt, sizeof(char), 16, fp_tar);  //写MD5码

		//关闭目标文件 
		fclose(fp_tar);

		//printf("%d\n",cnt);
	}

	//文件关闭 
	fclose(fp_in);

}