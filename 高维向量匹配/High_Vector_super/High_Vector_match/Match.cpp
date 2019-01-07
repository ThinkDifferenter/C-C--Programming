#include "Head.h"

void Match()
{
	//��������       
	int i = 0;
	int j = 0;
	int tmp = 0;
	int cnt_v = 0;
	int cnt_i = 0;

	//����������-����ÿ������ 
	float buf[1025];
	float *V_id;
	double norm = 0.0;


	//��ȷ�ϼ��ļ�
	char filename_in[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\verify_vector_new.fea";
	FILE * fp_in = fopen(filename_in, "rb");

	//Ŀ���ļ����� 
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//ƥ�����ļ�����
	char filename_result[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Result.fea";
	FILE * fp_result=fopen(filename_result, "wb+");;


	//�ж�ȷ���ļ��Ƿ�� 
	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//����ȷ�ϼ�������ƥ�� 
	while (cnt_v<50) 
	{
		cnt_v++;

		//�����ʼ�� 
		memset(buf, 0, sizeof(buf));

		//��ȡȷ�ϼ���һ������
		fread(buf, sizeof(float), 1025, fp_in);

		//ȡ��ȷ��������id
		V_id = (float *)buf;
		printf("Orign_id = %.0f\n", *V_id);

		//ȡģ
		norm = Norm(buf);
		tmp = (int)((norm - Min_norm) / Step);

		//�򿪲���Ŀ���ļ�
		sprintf(filename_tar, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_super\\%d.data", tmp);
		fp_tar = fopen(filename_tar, "rb");

		//�жϵ�ǰȷ�ϼ������ķ�������λ��
		double Min_distance = 10000.0;
		double Od = 0.0;
		float T_buf[1025];
		float Min_buf[1025];
		int flag = 0;

		//��ʼ����
		while (!feof(fp_tar))
		{
			cnt_i++;

			//��ʼ������
			memset(T_buf, 0, sizeof(T_buf));

			//��ȡ�����ļ�����
			fread(T_buf, sizeof(float), 1025 , fp_tar);
			
			//����ŷʽ�����ж�
			Od = O_distance(buf, T_buf);
			
			//������Сŷʽ����
			if (Od < Min_distance)
			{
				Min_distance = Od;

				for (j = 0; j < 1025; j++)
				{
					Min_buf[j] = T_buf[j];
				}
			}

		}

		//������С������д���ļ�
		fwrite(Min_buf, sizeof(float), 1025, fp_result);
		float *T_id;
		T_id = (float *)Min_buf;
		printf("Match_id = %.0f\n\n", *T_id);

		fclose(fp_tar);
	}

	//�ļ��ر� 
	fclose(fp_in);
	fclose(fp_result);

}