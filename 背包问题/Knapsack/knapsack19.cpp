#include<stdio.h>
#include<stdlib.h>

//定义结构 
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
	//信息读入
	FILE *fp;
	int j;
	float Val = 0;
	char FileName[1024] = "";


	sprintf(FileName, "knapsack19-.txt");
	if ((fp=fopen(FileName,"r"))==NULL)
	{   
		//读取文件失败
		printf("The file is not found");
		exit(0); 
	}

	//读入物品个数
	fscanf(fp,"%f",&Val);
	int m_Dim = Val;
	//创建数组 
	Date Node[m_Dim];
	printf("物品的个数为:%d\n",m_Dim);

	//读入口袋容积
	fscanf(fp,"%f",&Val);
	double m_Contain = Val;
	printf("口袋的容积为:%.2f\n",m_Contain);
	
	printf("\n\n----价值:\n");
	//读入每个物品的价值
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%f",&Val);
		Node[j].m_Profit = Val;
		printf("%.2f\t", Val);
	}

	printf("\n\n----体积:\n");
	//读入每个物品的体积
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%f",&Val);
		Node[j].m_Weight = Val;
		printf("%.2f\t", Val);
	} 
	fclose(fp);
	
	//赋值每个物件的平均价值
	for(j=0;j<m_Dim;j++)
	{
		Node[j].m_Averge=(Node[j].m_Profit/Node[j].m_Weight);
	} 	

	//排序物件的平均价值
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
 	//输出物件的平均价值
 	for(j=0;j<m_Dim;j++)
 	{
 		printf("第%d个物件的平均价值为:%.2f\n",j+1,Node[j].m_Averge);	
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
				printf("\n体积超限！\n"); 
				break;
			}			
		} 
	}
	
	printf("\n求和利润为:%.2f\n",Sum_profit);
	printf("求和体积为:%.2f\n",Sum_weight);
	printf("还剩余%.2f个单位体积\n\n\n",m_Contain-Sum_weight);		
	
	return 0;
}

