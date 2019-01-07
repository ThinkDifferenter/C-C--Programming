#include "Head.h"

void Match()
{
	//MD5��ʼ��
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
	char filename_in[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\verify_vector.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//Ŀ���ļ������ļ� 
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//����������-����ÿ������-���� 
	float buf[1025];

	//����������ʱ������ - ��һλ����Ϊ������id 
	unsigned char decrypt[16];

	//����ѹ�������ݴ洢
	int *compress1;
	int *compress2;

	//����id���ݴ洢 
	int *id;

	//�ж��ļ��Ƿ�� 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//���ݶ��벢���� 
	while (cnt<100) // �ļ�����������!feof(fp_in)
	{
		cnt++;

		//�����ʼ�� 
		memset(buf, 0, sizeof(buf));

		//��ȡȷ�ϼ���һ������
		fread(buf, sizeof(float), 1025, fp_in);

		//������ż�¼
		id = (int *)buf;
		printf("ID=%.0f\n", *id);

		//�������ݼ��� 
		MD5Update(&md5, (unsigned char*)buf + 4, 1024 * 4);

		//�������ݴ洢 
		MD5Final(&md5, decrypt);

		//�������ݴ���
		compress1 = (int *)decrypt;
		compress2 = (int *)(decrypt + 4);

		//printf("compress1=%d\n", *compress1);
		//printf("compress2=%d\n", *compress2);

		//ȡ���ж��������ĸ��ļ��� 
		x = abs((*compress1) % 100);
		y = abs((*compress2) % 100);

		//printf("x=%d\n", x);
		//printf("y=%d\n", y);

		//��Ŀ���ļ�
		sprintf(filename_tar, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file\\%d_%d.data", x, y);
		fp_tar = fopen(filename_tar, "rb");

		//�ó�Ŀ���ļ���ÿ����¼�����뵱ǰȷ������ƥ��
		int *T_id;
		unsigned char T_decrypt[16];
		int *T_compress1;
		int *T_compress2;
		int flag = 0;

		while (!feof(fp_tar))
		{
			memset(T_id, 0, sizeof(T_id));
			memset(T_decrypt, 0, sizeof(T_decrypt));

			fread(T_id, sizeof(int), 1, fp_tar);//��ID
			fread(T_decrypt, sizeof(char), 16, fp_tar); //��md5�� 

			T_compress1 = (int *)T_decrypt;
			T_compress2 = (int *)(T_decrypt + 4);

			//printf("%.6f\t",T_id[0]);

			if (*T_id == *id)
			{
				flag = 1;
				printf("��%d��ƥ��������idΪ:%.6f\n", cnt, *T_id);
				break;
			}
		}
		if (flag == 0)
		{
			printf("��%d��ƥ������û���ҵ�!\n", cnt);
		}

		//�ر�Ŀ���ļ� 
		fclose(fp_tar);
	}

	//�ļ��ر� 
	fclose(fp_in);
}