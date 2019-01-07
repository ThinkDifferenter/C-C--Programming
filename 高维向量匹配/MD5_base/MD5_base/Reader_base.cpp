#include "Head.h"

void Reader_base()
{
	//Ŀ���ļ���
	char * filename_in = "65_25.data";
	FILE * fp_in = fopen(filename_in, "rb");

	//��������
	int i = 0;
	int cnt = 0;
	float id[1];
	unsigned char decrypt[16];

	//����ѹ�������ݴ洢 
	int *compress1;
	int *compress2;

	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	while (!feof(fp_in))
	{
		memset(decrypt, 0, sizeof(decrypt));

		fread(id, sizeof(float), 1, fp_in);
		fread(decrypt, sizeof(char), 16, fp_in);

		//����������� 
		printf("\n\n========��%d���������Ϊ:%.0f=========\n", ++cnt, id[0]);
		for (i = 0; i<16; i++)
		{
			printf("%02x", decrypt[i]);
		}

		//�������ݴ���
		compress1 = (int *)decrypt;
		compress2 = (int *)(decrypt + 4);

		//ѹ����Ϣ���
		printf("\n%d\t", *compress1);
		printf("%d", *compress2);
	}

	fclose(fp_in);
}