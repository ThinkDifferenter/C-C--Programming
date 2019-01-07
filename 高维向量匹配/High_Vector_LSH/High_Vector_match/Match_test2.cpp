#include "Head.h"

void Match_test2()
{
	//��������       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//ȷ�ϼ�����ID
	float *id;

	//�ֲ����й�ϣ
	float H[K];

	//�ļ���ȡ��д�� 
	char filename_in[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\verify_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//Ŀ���ļ������ļ� 
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

	//���ݶ��벢���� 
	while (cnt<50) 
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
		LSH(buf + 1,H);

		//�ó�Ŀ���ļ���ÿ����¼�����뵱ǰȷ������ƥ��
		float *T_id;
		float T_buf[K + 1];
		float dis;

		//ֱ����IDƥ�����
		while (!feof(fp_tar))
		{
			memset(T_buf, 0, sizeof(T_buf));

			fread(T_buf, sizeof(float), K+1 , fp_tar); 

			T_id = (float *)T_buf;

			if (*T_id == *id)
			{
				printf("Match_id=%.0f\n", *T_id);
				printf("Orign H=%f\tMatch H=%f\n", H[0], T_buf[1]);

				dis = O_distance(H, T_buf + 1);
				printf("The distance is %f\n\n", dis);
				
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