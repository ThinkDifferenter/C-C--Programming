#include "head.h"

//��ÿ�������ļ��е���������ģ�Ĵ�С����
int main()
{
	//����
	int cnt = 0;
	int i = 0;
	int j = 0;
	int cnt = 0;
	unsigned char min_buf[4108];
	int min_index = 0;
	double min = BIG_NUM;
	double *tmp = NULL;

	//�������ݴ洢 ID+ģ+����
	unsigned char buf[4108];

	//�������ļ����� 
	char filename_sort[1024];
	FILE * fp_sort[1000];

	//�����ļ�����-1000���ļ� 
	for (i = 0; i<1000; i++)
	{
		sprintf(filename_sort, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_super_sort\\%d.data", i);
		fp_sort[i] = fopen(filename_sort, "wb+");
		fclose(fp_sort[i]);
	}

	//���������ļ����� 
	char filename_index[1024] = "";
	FILE * fp_index;

	//����Ŀ���ļ�
	char filename_tar[1024] = "";
	FILE * fp_tar;

	//��һ�������ļ���������
	for (i = 0; i<=1000; i++)
	{
		//�������ļ�
		sprintf(filename_index, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_super\\%d.data", i);
		fp_index = fopen(filename_index, "rb");

		//�򿪶�Ӧ�����ļ�
		sprintf(filename_tar, "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_super_sort\\%d.data", i);
		fp_tar = fopen(filename_tar, "wb");

		//��ȡ�ļ���С
		fseek(fp_index, 0L, SEEK_END);
		int size = ftell(fp_index);
		size = size / 4108;
		fseek(fp_index, 0L, SEEK_SET);

		for(i=0;i<size;i++)
		{
			//����������ļ�����
			for (j = 0; j<size; j++)
			{
				//��ʼ���ڴ�
				memset(buf, 0, sizeof(buf));
				fread(buf, sizeof(unsigned char), 4108, fp_index);

				tmp = (double *)(fp_index + 4);

				if (*tmp<min)
				{
					min = *tmp;

					//for (j = 0; j < 4018; j++)
					//{
					//	min_buf[j] = buf[j];
					//}
					min_index = cnt;
				}

				cnt++;
			}

			//�������ļ����ļ���λ����С�±��ϲ�����һ����¼
			fseek(fp_index, min_index, 0);
			fread(min_buf, sizeof(unsigned char), 4108, fp_index);

			//д���ļ� 
			fwrite(min_buf, sizeof(unsigned char), 4108, fp_tar);

			//�޸�����
			tmp = (double *)(fp_index + 4);
			*tmp = BIG_NUM;

			//�������ļ����ļ���λ����С�±��ϲ�д���ļ�
			fseek(fp_index, min_index, 0);
			fwrite(min_buf, sizeof(unsigned char), 4108, fp_index);

			//���ñ�ʶ
			min = BIG_NUM;
			tmp = NULL;
			memset(min_buf, 0, sizeof(min_buf));

			//�ļ��ض�λ
			fseek(fp_index, 0, 0);
		}

		
		fclose(fp_index);
		fclose(fp_tar);
	}

	return 0;
}