#include "Head.h"

void Reader_base()
{
	//Ŀ���ļ���
	char * filename_in = "D:\\��ά����ƥ��\\hdss_cnsoft2018\\Index_file_super\\91.data";
	FILE * fp_in = fopen(filename_in, "rb");

	//��������
	int cnt = 0;

	float id[1];
	double norm[1];

	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	while (!feof(fp_in))
	{
		fread(id, sizeof(float), 1, fp_in);
		fread(norm, sizeof(double), 1, fp_in);

		printf("\n========��%d������: ID=%.0f\t����: Norm=%f=========\n", ++cnt, id, norm);
	}

	fclose(fp_in);
	getchar();
}