#include "Head.h"

void Min_Max()
{
	//��������       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//�����Сֵ
	float min = 1000000000.0;
	float max = -1000000000.0;

	//�ֲ����й�ϣ
	float H = 0.0;

	//���ɸ�˹�������
	float a[1024];
	float tmp[1];
	
	//��ȡ���ȱ���������
	char filename_Gauus[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Gauss.data";
	FILE * fp_Gauss = fopen(filename_Gauus, "rb");
	fread(a, sizeof(float), 1024, fp_Gauss);  //���������a
	fread(tmp, sizeof(float), 1, fp_Gauss);   //��b
	float b = tmp[0];
	
	printf("%f\t", a[1023]);
	printf("%f\n", b);

	fclose(fp_Gauss);


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
	while (cnt<10) // �ļ�����������!feof(fp_in)
	{
		cnt++;

		//�����ʼ�� 
		memset(buf, 0, sizeof(buf));

		//��ȡһ������
		fread(buf, sizeof(float), 1025, fp_in);

		//���ɾֲ����й�ϣֵ
		H = LSH(a, buf + 4, b);

		printf("%f\n", H);

		if (min > H)
		{
			min = H;
		}

		if (max < H)
		{
			max = H;
		}

	}

	printf("min=%f\t max=%f\n", min, max);

	//�ļ��ر� 
	fclose(fp_in);

}