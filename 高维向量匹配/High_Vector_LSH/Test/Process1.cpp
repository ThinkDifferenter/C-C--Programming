#include "Head.h"

void Process1()
{
	//��������       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//id
	float *id;

	//H_1��H-2
	float H_1 = 0.0;
	float H_2 = 0.0;

	//�ֲ����й�ϣ
	float H[K];

	//�ļ���ȡ��д�� 
	char filename_in[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\base_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//Ŀ���ļ��� 
	//char filename_tar[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\verify_vector_new.fea";
	//FILE * fp_tar = fopen(filename_tar, "rb");

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
		
		//ȡid
		id = (float *)buf;
	
		//���ɾֲ����й�ϣֵ
		LSH(buf + 1,H);
		
		H_1 = Hash_1(H);
		H_2 = Hash_2(H);

		printf("%f\t%f\n", H_1, H_2);
		
		//float s = 0;
		//printf("id = %f\n", *id);
		//for (i = 0; i < K; i++)
		//{
		//	printf("%f\t", H[i]);
		//}
		//printf("\n\n");
		

		//д���Ӧ�ļ�
		//fwrite(id, sizeof(float), 1, fp_tar);  //дid
		//fwrite(H, sizeof(float), K , fp_tar);  //д����H

	}

	//�ļ��ر� 
	fclose(fp_in);
	//fclose(fp_tar);

}