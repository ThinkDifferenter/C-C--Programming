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

	//��ֵ����
	float mea = 0.0;
	float var = 0.0;

	//�ļ���ȡ��д�� 
	char filename_in[1024] = "D:\\��ά����ƥ��\\New_data\\vector_from_base.fea";
	FILE * fp_data = fopen(filename_in, "rb");

	//����������-����ÿ������-���� 
	float buf[1025];

	//�ж��ļ��Ƿ�� 
	if (fp_data == NULL)
	{
		printf("Can not open %s!\n", filename_in);
		exit(0);
	}

	//���ݶ��벢���� 
	while (cnt<100) // �ļ�����������!feof(fp_data)
	{
		cnt++;

		//�����ʼ�� 
		memset(buf, 0, sizeof(buf));

		//��ȡȷ�ϼ���һ������
		fread(buf, sizeof(float), 1025, fp_data);

		//������ż�¼
		printf("��%d������:ID=%.0f\t", cnt ,buf[0]);

		//�����ֵ
		mea = Mean(buf);

		//���㷽��
		var = Variance(buf);

		//�����ֵ�ͷ���
		printf("%f\t%f\n", mea, var);

	}

	endtime = clock();
	printf("\nRunning time :%d ms\n", endtime - begintime);

	//�ļ��ر� 
	fclose(fp_data);

	getchar();

	return 0;
}