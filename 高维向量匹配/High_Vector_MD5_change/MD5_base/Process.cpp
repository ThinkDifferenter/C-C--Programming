#include "Head.h"

void Process()
{
	//md5��ʼ��
	MD5_CTX md5;
	MD5Init(&md5);

	//��������       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//ѹ������ȡ��
	int x = 0;
	int y = 0;

	//�ļ���ȡ��д�� 
	char filename_in[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\base_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//Ŀ���ļ��� 
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//ѹ�������ļ����� 
	char filename[1024] = "";
	FILE * fp[100][100];

	//ѹ�������ļ����� - 10000���ļ� 
	for (i = 0; i<100; i++)
	{
		for (j = 0; j<100; j++)
		{
			sprintf(filename, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_md5\\%d_%d.data", i, j);
			fp[i][j] = fopen(filename, "wb+");
			fclose(fp[i][j]);
		}
	}

	//����������-����ÿ������-���� 
	float buf[1025];

	//����������ʱ������ 
	unsigned char decrypt[16];

	//����ѹ��������ָ�� 
	int *compress1;
	int *compress2;

	//�ж��ļ��Ƿ�� 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//���ݶ��벢���� 
	while (cnt<1000000) // �ļ�����������!feof(fp_in)
	{
		cnt++;

		//�����ʼ�� 
		memset(buf, 0, sizeof(buf));

		//��ȡһ������
		fread(buf, sizeof(float), 1025, fp_in);

		//�������ݼ��� 
		MD5Update(&md5, (unsigned char*)buf+4, 1024*4);

		//�������ݴ洢 
		MD5Final(&md5, decrypt);

		//�������ݴ���
		compress1 = (int *)decrypt;
		compress2 = (int *)(decrypt + 4);

		//ȡ�� 
		x = abs((*compress1) % 100);
		y = abs((*compress2) % 100);

		//��Ŀ���ļ�
		sprintf(filename_tar, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_md5\\%d_%d.data", x, y);
		fp_tar = fopen(filename_tar, "ab");

		//ͨ��ѹ����ά������Ϣ�жϸ�������д���ĸ��ļ�
		fwrite(buf, sizeof(float), 1025 , fp_tar);  //д����

		//�ر�Ŀ���ļ� 
		fclose(fp_tar);

	}

	//�ļ��ر� 
	fclose(fp_in);

}