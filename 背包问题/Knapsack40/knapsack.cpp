#include<stdio.h>
#include<stdlib.h>
#define Total_weight 22300
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
	double* m_Weight = new double[m_Dim];
	double* m_Profit = new double[m_Dim];
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
		m_Profit[j] = Val;
		printf("%.2f\t", Val);
	}

	printf("\n\n----体积:\n");
	//读入每个物品的体积
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%f",&Val);
		m_Weight[j] = Val;
		printf("%.2f\t", Val);
	} 
	fclose(fp);
	
	//计算物品的总价值
	double Sum_profit=0;
	for (j=0; j<m_Dim; j++)
	{
		Sum_profit+=m_Profit[j];
	}
	printf("\n物品的总价值为:%.2f\n",Sum_profit);
	
	//计算物品的总体积 
	double Sum_weight=0;
	double Other_weight=0; 
	for (j=0; j<m_Dim; j++)
	{
		Sum_weight+=m_Weight[j]; 
	}
	Other_weight=Sum_weight - Total_weight;
	printf("物品的总体积为:%.2f\n",Sum_weight); 
	printf("还有%.2f单位体积的物品装不下\n",Other_weight);
		
	//排序输出物品价值
	xuanze_sort(m_Profit,m_Dim);
	printf("\n\n物品价值排序:\n");
	for (j=0; j<m_Dim; j++)
	{
		printf("%.2f\t",m_Profit[j]); 
	}
	
	//排序输出物品体积 
	printf("\n\n物品体积排序:\n");
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