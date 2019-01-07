#include "Head.h"

void Match_test()
{
	//��������       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//id
	float *id;

	//H_1��H-2
	float *H_1;
	float *H_2;

	//�ֲ����й�ϣ
	float H[K];

	//�ļ���ȡ��д�� 
	char filename_in[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\verify_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//Ŀ���ļ��� 
	char filename_tar[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\H_compress.data";
	FILE * fp_tar = fopen(filename_tar, "rb");

	//����������-����ÿ������
	float buf[1025];

	//�ж��ļ��Ƿ�� 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	

	//��ȡ���ݼ������� 
	while (cnt<20) // �ļ�����������!feof(fp_in)
	{
		cnt++;

		//�����ʼ�� 
		memset(buf, 0, sizeof(buf));

		//��ȡһ������
		fread(buf, sizeof(float), 1025, fp_in);

		//ȡid
		id = (float *)buf;
		printf("��%d��ƥ������:\n", cnt);
		printf("Orign_id=%.0f\t", *id);

		//���ɾֲ����й�ϣֵ
		LSH(buf + 1, H);

		//�ó�Ŀ���ļ���ÿ����¼�����뵱ǰȷ������ƥ��
		float T_id=0.0;
		float T_buf[K + 1];
		float distance = 0.0;
		float O_H = 0.0;
		float M_H = 0.0;
		float min_d = 1000000;


		//������С����
		while (!feof(fp_tar))
		{
			memset(T_buf, 0, sizeof(T_buf));
			fread(T_buf, sizeof(float), K+1, fp_tar);

			//�������
			//distance = T_buf[1] - H[0];
			distance = O_distance(H, T_buf + 1);
			
			//printf("%f\n", distance);
			//�ж���С����
			if (distance < min_d)
			{
				//��С�������
				min_d = distance;

				//ID��¼
				T_id = T_buf[0];

				//ԭʼ��ϣֵ
				O_H = H[0];

				//ƥ���ϣֵ
				M_H = T_buf[1];
				
			}
		}

		printf("Match_id=%.0f\n", T_id);
		printf("Orign H=%f\tMatch H=%f\n", O_H, M_H);
		printf("The distance is %f\n\n", min_d);

		fseek(fp_tar, 0, 0);
	}

	//�ļ��ر� 
	fclose(fp_in);
	fclose(fp_tar);

}

