#include<stdio.h>
#include<stdlib.h>
void xuanze_sort (double *a,double n); 
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


	sprintf(FileName, "knapsack40.txt");
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
		//printf("%.2f\t", Val);
	}

	printf("\n\n----体积:\n");
	//读入每个物品的体积
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%f",&Val);
		Node[j].m_Weight = Val;
		//printf("%.2f\t", Val);
	} 
	fclose(fp);
	
	//计算每个物件的平均价值
	for(j=0;j<m_Dim;j++)
	{
		Node[j].m_Averge=(Node[j].m_Profit/Node[j].m_Weight);
	} 
	
	//输出每个物件的平均价值
	for(j=0;j<m_Dim;j++)
	{
		printf("第%d个物件的平均价值为:%.2f\n",j+1,Node[j].m_Averge);
	} 
		 
	//计算物品的总价值
//	double Total_profit=0;
//	for (j=0; j<m_Dim; j++)
//	{
//		Total_profit+=Node[j].m_Profit;
//	}
//	printf("\n物品的总价值为:%.2f\n",Total_profit);
	
	//计算物品的总体积 
//	double Total_weight=0;
//	double Other_weight=0; 
//	for (j=0; j<m_Dim; j++)
//	{
//		Total_weight+=Node[j].m_Weight; 
//	}
//	Other_weight=Total_weight - m_Contain;
//	printf("物品的总体积为:%.2f\n",Total_weight); 
//	printf("还有%.2f单位体积的物品装不下\n",Other_weight);
	
	//排序求得价值的平均值为17，体积的平均值为99
	//判断区间
	double Sum_profit=0;
	double Sum_weight=0;
	for (j=0; j<m_Dim; j++)
	{
		if(Node[j].m_Averge>0.10)
		{
			if(Sum_weight>m_Contain)
			{
				printf("体积超限！\n"); 
				break;
			}
			Sum_profit+=Node[j].m_Profit;
			Sum_weight+=Node[j].m_Weight;
			Node[j].flag=1;
		} 
	}
	printf("\n求和利润为:%.2f\n",Sum_profit);
	printf("求和体积为:%.2f\n\n\n",Sum_weight); 
	
//	for(j=0;j<m_Dim;j++)
//	{
//		if(Node[j].flag==1)
//		{
//			printf("选中%d个结点数据价值为:%.2f ，体积为:%.2f\n",j+1,Node[j].m_Profit,Node[j].m_Weight);
//		}
//	}
	
	for(j=0;j<m_Dim;j++)
	{
		if(Node[j].m_Averge==0.1)
		{
			printf("第%d个物件的价值为:%.2f,体积为:%.2f\n",j+1,Node[j].m_Profit,Node[j].m_Weight);
		}
	}	
	
	return 0;
}
