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
		//printf("%.2f\t", Val);
	}

	printf("\n\n----���:\n");
	//����ÿ����Ʒ�����
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%f",&Val);
		Node[j].m_Weight = Val;
		//printf("%.2f\t", Val);
	} 
	fclose(fp);
	
	//����ÿ�������ƽ����ֵ
	for(j=0;j<m_Dim;j++)
	{
		Node[j].m_Averge=(Node[j].m_Profit/Node[j].m_Weight);
	} 
	
	//���ÿ�������ƽ����ֵ
	for(j=0;j<m_Dim;j++)
	{
		printf("��%d�������ƽ����ֵΪ:%.2f\n",j+1,Node[j].m_Averge);
	} 
		 
	//������Ʒ���ܼ�ֵ
//	double Total_profit=0;
//	for (j=0; j<m_Dim; j++)
//	{
//		Total_profit+=Node[j].m_Profit;
//	}
//	printf("\n��Ʒ���ܼ�ֵΪ:%.2f\n",Total_profit);
	
	//������Ʒ������� 
//	double Total_weight=0;
//	double Other_weight=0; 
//	for (j=0; j<m_Dim; j++)
//	{
//		Total_weight+=Node[j].m_Weight; 
//	}
//	Other_weight=Total_weight - m_Contain;
//	printf("��Ʒ�������Ϊ:%.2f\n",Total_weight); 
//	printf("����%.2f��λ�������Ʒװ����\n",Other_weight);
	
	//������ü�ֵ��ƽ��ֵΪ17�������ƽ��ֵΪ99
	//�ж�����
	double Sum_profit=0;
	double Sum_weight=0;
	for (j=0; j<m_Dim; j++)
	{
		if(Node[j].m_Averge>0.10)
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
	printf("\n�������Ϊ:%.2f\n",Sum_profit);
	printf("������Ϊ:%.2f\n\n\n",Sum_weight); 
	
//	for(j=0;j<m_Dim;j++)
//	{
//		if(Node[j].flag==1)
//		{
//			printf("ѡ��%d��������ݼ�ֵΪ:%.2f �����Ϊ:%.2f\n",j+1,Node[j].m_Profit,Node[j].m_Weight);
//		}
//	}
	
	for(j=0;j<m_Dim;j++)
	{
		if(Node[j].m_Averge==0.1)
		{
			printf("��%d������ļ�ֵΪ:%.2f,���Ϊ:%.2f\n",j+1,Node[j].m_Profit,Node[j].m_Weight);
		}
	}	
	
	return 0;
}
