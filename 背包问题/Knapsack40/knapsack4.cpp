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
	
	//计算每个物件的平均价值
	double Avg_Profit[m_Dim];
	for(j=0;j<m_Dim;j++)
	{
		Avg_Profit[j]=Node[j].m_Profit/Node[j].m_Weight;
	} 
	
	//排序输出每个物件的平均价值
	xuanze_sort(Avg_Profit,m_Dim);
	printf("平均价值排序:\n");
	for(j=0;j<m_Dim;j++)
	{
		printf("第%d个物件平均价值为:%.2f\n",j+1,Avg_Profit[j]);
	} 
	
 
		 
//	根据物件平均价值排序设定参数 
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
				printf("体积超限！\n"); 
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
			printf("选中%d个结点数据价值为:%.2f ，体积为:%.2f\n",j+1,Node[j].m_Profit,Node[j].m_Weight);
		}
	}
	
	printf("\n\n求和利润为:%.2f\n",Sum_profit);
	printf("求和体积为:%.2f\n",Sum_weight);
	printf("还剩余%.2f个单位体积\n\n\n",m_Contain-Sum_weight);
	
	//没有被选中的物件	
	
	for(j=0;j<m_Dim;j++)
	{
		if(Node[j].flag!=1)
		{
			printf("没选中%d个结点数据价值为:%.2f ，体积为:%.2f ，平均价值为:%.2f\n",j+1,Node[j].m_Profit,Node[j].m_Weight,Node[j].m_Averge);
		}
	}	
	
	//手动添加物件 以下是平均价值为0.1的物件 

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
	
	printf("\n\n求和利润为:%.2f\n",Sum_profit);
	printf("求和体积为:%.2f\n",Sum_weight);
	printf("还剩余%.2f个单位体积\n\n\n",m_Contain-Sum_weight);	
	
	return 0;
}

//选择排序 
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
