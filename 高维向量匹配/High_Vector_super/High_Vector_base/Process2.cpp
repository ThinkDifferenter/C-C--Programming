#include "Head.h"

//�������ģ�����������洢��һ�������ļ���-����ļ������ݽ�������
//���ݱ��棺ID + ģ + ���� 4+8+1024*4

void Process2()
{

	//��������       
	int i = 0;
	int tmp = 0;
	int cnt = 0;

	//�ļ���ȡ��д�� 
	char filename_in[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\base_vectors.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//Ŀ���ļ��� 
	char filename_tar[1024] = "";
	FILE * fp_tar = fopen(filename_in, "wb+");;

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
		tmp = (int)((norm[0] - 17.273566) / 0.0024491);

		//ͨ�������ж����������ļ���
		fwrite(buf, sizeof(float), 1, fp_tar);  //дID 
		fwrite(norm, sizeof(double), 1, fp_tar); //д����

		
	}

	//�ļ��ر� 
	fclose(fp_in);
	fclose(fp_tar);

}