#include<stdio.h>
#include<stdlib.h>

int  main()
{
	//信息读入
	FILE *fp;
	int j;
	int Val = 0;
	char FileName[1024] = "";


	sprintf(FileName, "knapsack40.txt");
	if ((fp=fopen(FileName,"r"))==NULL)
	{   
		//读取文件失败
		printf("The file is not found");
		exit(0); 
	}

	//读入物品个数
	fscanf(fp,"%d",&Val);
	int m_Dim = Val;
	//创建数组 
	int* m_Weight = new int[m_Dim];
	int* m_Profit = new int[m_Dim];
	printf("物品的个数为:%d\n",m_Dim);

	//读入口袋容积
	fscanf(fp,"%d",&Val);
	int m_Contain = Val;
	printf("口袋的容积为:%d\n",m_Contain);
	
	printf("\n\n----价值:\n");
	//读入每个物品的价值
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%d",&Val);
		m_Profit[j] = Val;
		printf("%d\t", Val);
	}

	printf("\n\n----体积:\n");
	//读入每个物品的体积
	for (j=0; j<m_Dim; j++)
	{
		fscanf(fp,"%d",&Val);
		m_Weight[j] = Val;
		printf("%d\t", Val);
	} 
	fclose(fp);

	
	//定义当前容器中物件的价值和体积 
	int C_weight=0,C_profit1=0,C_profit2=0;
	
	//构建每个物件与容器大小的二维数组，其值表示当前条件下容器可装最大价值的物件 
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
			//装不下 
			if(m_Weight[j]>C_weight)
			{
				P[j][C_weight]=P[j-1][C_weight];
			}
			//能装下 
			else
			{
				//装 
				C_profit1=P[j-1][C_weight-m_Weight[j]]+m_Profit[j];
				//不装 
				C_profit2=P[j-1][C_weight];
				//价值比较 
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
	
	printf("最大价值为:%d\n",P[m_Dim][m_Contain]);
	return 0;
}


