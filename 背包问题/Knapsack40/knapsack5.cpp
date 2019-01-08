#include<stdio.h>
#include<stdlib.h>

int  main()
{
	//��Ϣ����
	FILE *fp;
	int j;
	int Val = 0;
	char FileName[1024] = "";


	sprintf(FileName, "knapsack40.txt");
	if ((fp=fopen(FileName,"r"))==NULL)
	{   
		//��ȡ�ļ�ʧ��
		printf("The file is not found");
		exit(0); 
	}

	//������Ʒ����
	fscanf(fp,"%d",&Val);
	int m_Dim = Val;
	//�������� 
	int* m_Weight = new int[m_Dim];
	int* m_Profit = new int[m_Dim];
	printf("��Ʒ�ĸ���Ϊ:%d\n",m_Dim);

	//����ڴ��ݻ�
	fscanf(fp,"%d",&Val);
	int m_Contain = Val;
	printf("�ڴ����ݻ�Ϊ:%d\n",m_Contain);
	
	printf("\n\n----��ֵ:\n");
	//����ÿ����Ʒ�ļ�ֵ
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%d",&Val);
		m_Profit[j] = Val;
		printf("%d\t", Val);
	}

	printf("\n\n----���:\n");
	//����ÿ����Ʒ�����
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%d",&Val);
		m_Weight[j] = Val;
		printf("%d\t", Val);
	} 
	fclose(fp);

	
	//���嵱ǰ����������ļ�ֵ����� 
	int C_weight=0,C_profit1=0,C_profit2=0;
	
	//����ÿ�������������С�Ķ�ά���飬��ֵ��ʾ��ǰ������������װ����ֵ����� 
	int P[m_Dim][m_Contain];
	for(int m=0;m<=m_Dim;m++)
	{
		for(int n=0;n<=m_Contain;n++)
		{
			P[m_Dim][m_Contain]=0;
		}
	}
	
	
	for(j=0;j<=m_Dim;j++)
	{
		for(C_weight=0;C_weight<=m_Contain;C_weight++)
		{
			//װ���� 
			if(m_Weight[j]>C_weight)
			{
				P[j][C_weight]=P[j-1][C_weight];
			}
			//��װ�� 
			else
			{
				//װ 
				C_profit1=P[j-1][C_weight-m_Weight[j]]+m_Profit[j];
				//��װ 
				C_profit2=P[j-1][C_weight];
				//��ֵ�Ƚ� 
				if(C_profit1>C_profit2)
				{
					P[j][C_weight]=C_profit1;
				}
				else
				{
					P[j][C_weight]=C_profit2;	
				}
			}
		}
	} 
	
	printf("����ֵΪ:%d\n",P[m_Dim][m_Contain]);
	return 0;
}


