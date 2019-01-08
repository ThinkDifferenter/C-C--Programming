#include<stdio.h>
#include<stdlib.h>

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


	sprintf(FileName, "knapsack19-.txt");
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

	//���������ƽ����ֵ
	int i,k;
	Date t;
	for(i=0;i<m_Dim;i++)
	{
		k=i;
		for(j=i+1;j<m_Dim;j++)
		{
			if(Node[j].m_Averge>Node[k].m_Averge)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			t=Node[i];
			Node[i]=Node[k];
			Node[k]=t;
		}
	}
 	//��������ƽ����ֵ
 	for(j=0;j<m_Dim;j++)
 	{
 		printf("��%d�������ƽ����ֵΪ:%.2f\n",j+1,Node[j].m_Averge);	
 	} 

	double Sum_profit=0;
	double Sum_weight=0;
	double tmp=0;
	for (j=0; j<m_Dim; j++)
	{
		if(Node[j].m_Averge)
		{

			Sum_weight+=Node[j].m_Weight;
			Node[j].flag=1;
			if(Sum_weight>m_Contain)
			{
				tmp=Node[j].m_Weight;
				break;
			}			
		} 
	}
	
	Sum_weight=0;
	for (j=0; j<m_Dim; j++)
	{
		if(Node[j].m_Averge)
		{

			Sum_profit+=Node[j].m_Profit;
			Sum_weight+=Node[j].m_Weight;
			Node[j].flag=1;
			if(Sum_weight>m_Contain-tmp)
			{
				printf("\n������ޣ�\n"); 
				break;
			}			
		} 
	}
	
	printf("\n�������Ϊ:%.2f\n",Sum_profit);
	printf("������Ϊ:%.2f\n",Sum_weight);
	printf("��ʣ��%.2f����λ���\n\n\n",m_Contain-Sum_weight);		
	
	return 0;
}

