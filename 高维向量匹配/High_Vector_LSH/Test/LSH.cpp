#include "Head.h"

void LSH(float *v,float H[K])
{
	//��������
	int i = 0;
	int j = 0;
	
	//��ϣ���ݼ�¼
	float Sum = 0.0;

	//�����洢
	float a[1024];
	float b[1];

	//�򿪲����ļ�
	char filename_Gauus[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Test\\Gauss.data";
	FILE * fp_Gauss = fopen(filename_Gauus, "rb");

	//for (int i = 0; i < 10; i++)
	//	printf("%f  ", v[i]);


	for (i = 0; i < K; i++)
	{
		//��ȡ����a,b
		fread(a, sizeof(float), 1024, fp_Gauss);  //a
		fread(b, sizeof(float), 1, fp_Gauss);     //b



		for (j = 0; j < 1024; j++)
		{
			
			Sum += a[j] * v[j];
		}
		//printf("%f ", b[0]);
		H[i] = (Sum + b[0])/W;
		H[i] = floor(H[i]);
		//printf("%f ",floor(H[i]));
		Sum = 0.0;
	}

	fclose(fp_Gauss);
}