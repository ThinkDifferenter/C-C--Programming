#include "Head.h"
void newdata()
{
	char filename_in[1024] = "C:\\Users\\JRW\\Desktop\\Data\\verify_vector_new.fea";
	FILE *fp_in = fopen(filename_in, "rb");

	char file_tar1[1024] = "C:\\Users\\JRW\\Desktop\\Data\\newverify.data";
	FILE *fp1 = fopen(file_tar1, "wb+");

	if (fp_in == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	float buf[1025];
	float newbuf[8];
	float sum = 0;
	int i, j;

	while (!feof(fp_in))
	{
		memset(newbuf, 0, sizeof(newbuf));
		memset(buf, 0, sizeof(buf));
		fread(buf, sizeof(float), 1025, fp_in);
		//float *id = buf;
	
			for (i = 0; i < 8; i++)
			{
				for (j = i * 128 + 1; j < (i + 1) * 128 + 1; j++)
				{
					sum += buf[j];
				}
				newbuf[i] = sum/128;
				sum = 0;
				printf("%f ", newbuf[i]);
			}
			//printf("%f ", *buf);
			fread(buf, sizeof(float), 1, fp1);
			fread(newbuf, sizeof(float), 8, fp1);
		
		
	
	}
	fclose(fp_in);
	fclose(fp1);

	printf("********\n\n");

}