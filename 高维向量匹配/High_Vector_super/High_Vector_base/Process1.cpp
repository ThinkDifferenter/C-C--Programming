#include "Head.h"

//�������ļ����ֵ�����ļ�-����ļ������ݽ�������
//���ݱ��棺ID + ģ + ���� 4+8+1024*4
void Process1()
{
	//��������       
	int i = 0;
	int tmp = 0;
	int cnt = 0;

	//�ļ���ȡ��д�� 
	char filename_in[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\base_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//Ŀ���ļ��� 
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//���������ļ����� 
	char filename[1024] = "";
	FILE * fp[500];

	//ѹ�������ļ����� - 1000���ļ� 
	for (i = 0; i<500; i++)
	{
			sprintf(filename, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_super_500\\%d.data", i);
			fp[i] = fopen(filename, "wb+");
			fclose(fp[i]);
	}

	//����������-����ÿ������
	float buf[1025];
	double norm[1];

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
		norm[0] = 0.0;
		tmp = 0;

		//��ȡһ������
		fread(buf, sizeof(float), 1025, fp_in);

		//��������ж��������ĸ��ļ�
		norm[0] = Norm(buf);
		tmp = (int)( (norm[0] - Min_norm) / Step);
		
		//��Ŀ���ļ�
		sprintf(filename_tar, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_super_500\\%d.data",tmp);
		fp_tar = fopen(filename_tar, "ab");

		//ͨ�������ж����������ļ���
		//fwrite(buf, sizeof(float), 1, fp_tar);  //дID 
		//fwrite(norm, sizeof(double), 1, fp_tar); //д����
		//fwrite(buf+4, sizeof(float), 1024, fp_tar); //д����
		fwrite(buf, sizeof(float), 1025, fp_tar); //д����

		//�ر�Ŀ���ļ� 
		fclose(fp_tar);
	}

	//�ļ��ر� 
	fclose(fp_in);
}