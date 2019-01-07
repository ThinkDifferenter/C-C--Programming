#include "Head.h"

void Match_test()
{
	//��������       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//ȷ�ϼ�����ID
	float *id;

	//�ֲ����й�ϣ
	float H[K];

	//H_1��H-2
	float H_1 = 0.0;
	float H_2 = 0.0;

	//�ļ���ȡ��д�� 
	char filename_in[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\verify_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//Ŀ���ļ������ļ� 
	char filename_tar[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\base_vector_new.fea";
	FILE * fp_tar = fopen(filename_tar, "rb");


	//����������-����ÿ������
	float buf[1025];

	//�ж��ļ��Ƿ�� 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//���ݶ��벢���� 
	while (cnt<5)
	{
		cnt++;

		//�����ʼ�� 
		memset(buf, 0, sizeof(buf));

		//��ȡȷ�ϼ���һ������
		fread(buf, sizeof(float), 1025, fp_in);

		//ȡID
		id = (float *)buf;
		printf("��%d��ƥ������:\n", cnt);
		printf("Orign_id=%.0f\t", *id);

		//���ɾֲ����й�ϣֵ
		LSH(buf + 1, H);

		H_1 = Hash_1(H);
		H_2 = Hash_2(H);

		printf("H_1=%f\tH_2=%f\n", H_1, H_2);

		//�ó�Ŀ���ļ���ÿ����¼�����뵱ǰȷ������ƥ��
		float *T_id;
		float T_buf[1025];
		float dis;
		//�ֲ����й�ϣ
		float T_H[K];

		//H_1��H-2
		float T_H_1 = 0.0;
		float T_H_2 = 0.0;

		//ֱ����IDƥ�����
		while (!feof(fp_tar))
		{
			memset(T_buf, 0, sizeof(T_buf));

			fread(T_buf, sizeof(float), 1025 , fp_tar);

			T_id = (float *)T_buf;

			if (*T_id == *id)
			{
				printf("Match_id=%.0f\t", *T_id);
				
				//���ɾֲ����й�ϣֵ
				LSH(T_buf + 1, T_H);

				T_H_1 = Hash_1(T_H);
				T_H_2 = Hash_2(T_H);

				printf("T_H_1=%f\tT_H_2=%f\n", T_H_1, T_H_2);

				fseek(fp_tar, 0, 0);

				break;
			}
		}

		fseek(fp_tar, 0, 0);

	}

	//�ļ��ر� 
	fclose(fp_in);
	fclose(fp_tar);

}