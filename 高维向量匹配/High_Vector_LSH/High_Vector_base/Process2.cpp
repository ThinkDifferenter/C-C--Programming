#include "Head.h"

void Process()
{
	//��������       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//ȡ��
	int Remainder = 0;

	//�ֲ����й�ϣ
	float H = 0.0;



	//��ϣ�ļ����� 
	char filename[1024] = "";
	FILE * fp[1000];

	//��ϣ�ļ����� - 1000 
	for (i = 0; i<1000; i++)
	{
		sprintf(filename, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_LSH\\%d.data", i);
		fp[i] = fopen(filename, "wb+");
		fclose(fp[i]);
	}

	//Ŀ���ļ��� 
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//�ļ���ȡ��д�� 
	char filename_in[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\base_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//����������-����ÿ������
	float buf[1025];

	//�ж��ļ��Ƿ�� 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//��ȡ���ݼ������� 
	while (cnt<100) // �ļ�����������!feof(fp_in)
	{
		cnt++;

		//�����ʼ�� 
		memset(buf, 0, sizeof(buf));

		//��ȡһ������
		fread(buf, sizeof(float), 1025, fp_in);

		//���ɾֲ����й�ϣֵ
		H = LSH(buf + 4);

		printf("%f\n", H);

		//ȡ�� 
		Remainder = abs((int)H % 1000);

		//��Ŀ���ļ�
		sprintf(filename_tar, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_LSH\\%d.data", Remainder);
		fp_tar = fopen(filename_tar, "ab");

		//д���Ӧ�ļ�
		fwrite(buf, sizeof(float), 1025, fp_tar);  //д����

												   //�ر�Ŀ���ļ� 
		fclose(fp_tar);
	}

	//�ļ��ر� 
	fclose(fp_in);

}