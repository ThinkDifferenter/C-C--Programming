#include<stdio.h>
#include<stdlib.h>
void xuanze_sort (double *a,double n); 
//����ṹ 
typedef struct node
{
	double m_Weight;
	double m_Profit;
	double m_Averge;
	int flag;
}Date;

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
	Date Node[m_Dim];
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
		Node[j].m_Profit = Val;
		printf("%.2f\t", Val);
	}

	printf("\n\n----���:\n");
	//����ÿ����Ʒ�����
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%f",&Val);
		Node[j].m_Weight = Val;
		printf("%.2f\t", Val);
	} 
	fclose(fp);
	
	//��ֵÿ�������ƽ����ֵ
	for(j=0;j<m_Dim;j++)
	{
		Node[j].m_Averge=(Node[j].m_Profit/Node[j].m_Weight);
	} 	
	
	//����ÿ�������ƽ����ֵ
	double Avg_Profit[m_Dim];
	for(j=0;j<m_Dim;j++)
	{
		Avg_Profit[j]=Node[j].m_Profit/Node[j].m_Weight;
	} 
	
	//�������ÿ�������ƽ����ֵ
	xuanze_sort(Avg_Profit,m_Dim);
	printf("ƽ����ֵ����:\n");
	for(j=0;j<m_Dim;j++)
	{
		printf("��%d�����ƽ����ֵΪ:%.2f\n",j+1,Avg_Profit[j]);
	} 
	
 
		 
//	�������ƽ����ֵ�����趨���� 
//  >=0.1 3958 477
//  >0.1  3953 527 
	double Sum_profit=0;
	double Sum_weight=0;
	for (j=0; j<m_Dim; j++)
	{
		if(Node[j].m_Averge>0.1)
		{
			if(Sum_weight>m_Contain)
			{
				printf("������ޣ�\n"); 
				break;
			}
			Sum_profit+=Node[j].m_Profit;
			Sum_weight+=Node[j].m_Weight;
			Node[j].flag=1;
		} 
	}
 
	
	for(j=0;j<m_Dim;j++)
	{
		if(Node[j].flag==1)
		{
			printf("ѡ��%d��������ݼ�ֵΪ:%.2f �����Ϊ:%.2f\n",j+1,Node[j].m_Profit,Node[j].m_Weight);
		}
	}
	
	printf("\n\n�������Ϊ:%.2f\n",Sum_profit);
	printf("������Ϊ:%.2f\n",Sum_weight);
	printf("��ʣ��%.2f����λ���\n\n\n",m_Contain-Sum_weight);
	
	//û�б�ѡ�е����	
	
	for(j=0;j<m_Dim;j++)
	{
		if(Node[j].flag!=1)
		{
			printf("ûѡ��%d��������ݼ�ֵΪ:%.2f �����Ϊ:%.2f ��ƽ����ֵΪ:%.2f\n",j+1,Node[j].m_Profit,Node[j].m_Weight,Node[j].m_Averge);
		}
	}	
	
	//�ֶ������� ������ƽ����ֵΪ0.1����� 

//	Sum_profit+=Node[37-1].m_Profit;
//	Sum_weight+=Node[37-1].m_Weight; 
	
	Sum_profit+=Node[108-1].m_Profit;
	Sum_weight+=Node[108-1].m_Weight;
	
//	Sum_profit+=Node[162-1].m_Profit;
//	Sum_weight+=Node[162-1].m_Weight;
	
	Sum_profit+=Node[166-1].m_Profit;
	Sum_weight+=Node[166-1].m_Weight;

	Sum_profit+=Node[259-1].m_Profit;
	Sum_weight+=Node[259-1].m_Weight;

	Sum_profit+=Node[267-1].m_Profit;
	Sum_weight+=Node[267-1].m_Weight;
	
//	Sum_profit+=Node[277-1].m_Profit;
//	Sum_weight+=Node[277-1].m_Weight;
	
	printf("\n\n�������Ϊ:%.2f\n",Sum_profit);
	printf("������Ϊ:%.2f\n",Sum_weight);
	printf("��ʣ��%.2f����λ���\n\n\n",m_Contain-Sum_weight);	
	
	return 0;
}

//ѡ������ 
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
