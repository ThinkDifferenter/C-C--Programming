#include "Head.h"

void Random_make()
{
	int i = 0;

	float a[1024];
	float b[1];

	char filename_Gauus[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Test\\Gauss.data";
	FILE * fp_Gauss = fopen(filename_Gauus, "wb+");

	for (i = 0; i < K; i++)
	{ 
		//�����ʼ�� 
		memset(a, 0, sizeof(a));

		//���ɸ�˹�������
		a_Random(a, 1024);
		
		//����ָ�����������
		b[0] = b_Random(0, W);
		
		//�����˹����������ļ�
		fwrite(a, sizeof(float), 1024, fp_Gauss);  //a
		fwrite(b, sizeof(float), 1, fp_Gauss);     //b
		
	}

	fclose(fp_Gauss);
}