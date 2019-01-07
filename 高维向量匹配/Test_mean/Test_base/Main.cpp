#include "head.h"

int main(int argc, char *argv[])
{
	int begintime;
	int endtime;

	begintime = clock();

	//��������       
	int i = 0;
	int j = 0;
	int cnt = 0;

	//��ȷ�ϼ��ļ�-�ļ���ȡ��д�� 
	char filename_ver[1024] = "D:\\��ά����ƥ��\\New_data\\verify_vector.fea";
	FILE * fp_ver = fopen(filename_ver, "rb");

	//�����ݼ��ļ�-�ļ���ȡ��д��
	char filename_base[1024] = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\base_vectors.fea";
	FILE * fp_base = fopen(filename_base, "rb");

	//�����ҵ���������ŵ��ļ���
	char file[1024] = "D:\\��ά����ƥ��\\New_data\\vector_from_base.fea";
	FILE * fp_tar = fopen(file, "wb+");
	fclose(fp_tar);
	

	//ȷ�ϼ�-����������-����ÿ������ 
	float buf_ver[1025];

	//���ݼ��������
	float buf_base[1025];

	//�ж��ļ��Ƿ�� 
	if (fp_ver == NULL)
	{
		printf("Can not open %s!\n", filename_ver);
		exit(0);
	}

	if (fp_base == NULL)
	{
		printf("Can not open %s!\n", filename_base);
		exit(0);
	}

	//���ݶ���Ա�
	while (cnt<100) // �ļ�����������!feof(fp_ver)
	{
		cnt++;

		//�����ʼ�� 
		memset(buf_ver, 0, sizeof(buf_ver));

		//��ȡȷ�ϼ���һ������
		fread(buf_ver, sizeof(float), 1025, fp_ver);

		//������ż�¼
		//printf("��%d������:ID=%.0f\t", cnt, buf[0]);
		
		while (1)
		{
			//�����ʼ�� 
			memset(buf_base, 0, sizeof(buf_base));

			//��ȡ���ݼ���һ������
			fread(buf_base, sizeof(float), 1025, fp_base);

			//�Ա�
			if (buf_ver[0] == buf_base[0])
			{
				//��Ŀ���ļ�
				fp_tar = fopen(file, "ab");

				//���ݼ���������
				fwrite(buf_base, sizeof(float), 1025 , fp_tar);
				
				//�ر�Ŀ���ļ�
				fclose(fp_tar);

				//���ݼ��ļ�ָ���ض�λ
				fseek(fp_base, 0 , SEEK_SET);

				break;
			}

		}

	}

	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);

	//�ļ��ر� 
	fclose(fp_ver);
	fclose(fp_base);

	getchar();

	return 0;
}


/*	int fseek(FILE *stream, long offset, int fromwhere);

	��һ������streamΪ�ļ�ָ��

�����ڶ�������offsetΪƫ������������ʾ����ƫ�ƣ�������ʾ����ƫ��

��������������origin�趨���ļ������￪ʼƫ��,����ȡֵΪ��SEEK_CUR�� SEEK_END �� SEEK_SET

����SEEK_SET�� �ļ���ͷ

����SEEK_CUR�� ��ǰλ��

����SEEK_END�� �ļ���β

  ������SEEK_SET,SEEK_CUR��SEEK_END����Ϊ0��1��2.
*/