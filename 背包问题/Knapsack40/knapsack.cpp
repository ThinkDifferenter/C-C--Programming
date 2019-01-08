#include<stdio.h>
#include<stdlib.h>
#define Total_weight 22300
void xuanze_sort (double *a,double n);
int  main()
{
	//��Ϣ����
	FILE *fp;
	int j;
	float Val = 0;
	char FileName[1024] = "";


	sprintf(FileName, "knapsack40.txt");
	if ((fp=fopen(FileName,"r"))==NULL)
	{   
		//��ȡ�ļ�ʧ��
		printf("The file is not found");
		exit(0); 
	}

	//������Ʒ����
	fscanf(fp,"%f",&Val);
	int m_Dim = Val;
	//�������� 
	double* m_Weight = new double[m_Dim];
	double* m_Profit = new double[m_Dim];
	printf("��Ʒ�ĸ���Ϊ:%d\n",m_Dim);

	//����ڴ��ݻ�
	fscanf(fp,"%f",&Val);
	double m_Contain = Val;
	printf("�ڴ����ݻ�Ϊ:%.2f\n",m_Contain);
	
	printf("\n\n----��ֵ:\n");
	//����ÿ����Ʒ�ļ�ֵ
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%f",&Val);
		m_Profit[j] = Val;
		printf("%.2f\t", Val);
	}

	printf("\n\n----���:\n");
	//����ÿ����Ʒ�����
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%f",&Val);
		m_Weight[j] = Val;
		printf("%.2f\t", Val);
	} 
	fclose(fp);
	
	//������Ʒ���ܼ�ֵ
	double Sum_profit=0;
	for (j=0; j<m_Dim; j++)
	{
		Sum_profit+=m_Profit[j];
	}
	printf("\n��Ʒ���ܼ�ֵΪ:%.2f\n",Sum_profit);
	
	//������Ʒ������� 
	double Sum_weight=0;
	double Other_weight=0; 
	for (j=0; j<m_Dim; j++)
	{
		Sum_weight+=m_Weight[j]; 
	}
	Other_weight=Sum_weight - Total_weight;
	printf("��Ʒ�������Ϊ:%.2f\n",Sum_weight); 
	printf("����%.2f��λ�������Ʒװ����\n",Other_weight);
		
	//���������Ʒ��ֵ
	xuanze_sort(m_Profit,m_Dim);
	printf("\n\n��Ʒ��ֵ����:\n");
	for (j=0; j<m_Dim; j++)
	{
		printf("%.2f\t",m_Profit[j]); 
	}
	
	//���������Ʒ��� 
	printf("\n\n��Ʒ�������:\n");
	xuanze_sort(m_Weight,m_Dim);
	for (j=0; j<m_Dim; j++)
	{
		printf("%.2f\t",m_Weight[j]);
	}
	
	
}

void xuanze_sort (double *a,double n)
{
	int i,j,k;
	double t;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[k])
			{
				k=j;
			}
		}
		if(k!=i)
		{
			t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}
}