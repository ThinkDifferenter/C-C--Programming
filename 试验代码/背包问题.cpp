#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct
{
	int object;
	int weight;
	int value;
}KnapSack;

KnapSack * knapsack;//背包数组，用malloc或new动态创建
int num;//物体的个数
int container;//背包的最大容量
int**array=NULL;//用来存放子问题的结果

//动态创建背包
void Create_KnapSack()
{
	//文件读入 
	FILE *fp;
	int Val = 0;
	char FileName[1024] = "";
	
	sprintf(FileName, "knapsack16-.txt");
	if ((fp=fopen(FileName,"r"))==NULL)
	{   
		//读取文件失败
		printf("The file is not found");
		exit(0); 
	}
	
	//读入物品个数
	fscanf(fp,"%d",&Val);
	int m_Dim = Val;
	num=m_Dim;
	knapsack=(KnapSack *)malloc(sizeof(KnapSack)*(num+1));
	
	//读入口袋容积
	fscanf(fp,"%d",&Val);
	int m_Contain = Val;
	container=m_Contain;
//	printf("口袋的容积为:%.2f\n",m_Contain);
	
//	printf("\n\n----价值:\n");
	//读入每个物品的价值
	for (int j=1; j<=num; j++)
	{
		fscanf(fp,"%d",&Val);
		knapsack[j].object=j;
		knapsack[j].value = Val;
		//printf("%.2f\t", Val);
	}

//	printf("\n\n----体积:\n");
	//读入每个物品的体积
	for (int j=1; j<=num; j++)
	{
		fscanf(fp,"%d",&Val);
		knapsack[j].weight = Val;
//		printf("%.2f\t", Val);
	} 
	fclose(fp);
	
				
	char c;
//	printf("input the number of objects\n");
//	scanf("%d",&num);
	knapsack=new KnapSack[m_Dim+1];
//	printf("input weight and value of %d objects,like Num:Weight-Value\n",num);
//	for(int i=1;i<=m_Dim;i++)
//	{
//		scanf("%d%c%d%c%d",&knapsack[i].object,&c,&knapsack[i].weight,&c,&knapsack[i].value);
//		getchar();//为了获取空格或其他输入
//	}
//	int k=knapsack[num].value;
//	printf("%d\n",k);
//	printf("input the volume of the knapsack:\n");
	
}

//确定最优子问题
void Resolve_KnapSack()
{
	int k=knapsack[num].value;
	printf("%d",k);
	//创建动态二维数组m[num][container]
	array=(int**)malloc((num+1)*sizeof(int*));
	for(int i=0;i<=num;i++)
	array[i]=(int*)malloc((container+1)*sizeof(int));
	//
	for(int j=0;j<=container;j++)
	array[num][j]=(j>=knapsack[num].weight)?knapsack[num].value:0;
	//子问题的最优结果
	for(int m=num-1;m>0;m--)
	for(int n=0;n<=container;n++)
	if(n>knapsack[m].weight&&array[m+1][n]<=array[m+1][n-knapsack[m].weight]+knapsack[m].value)
	array[m][n]=array[m+1][n-knapsack[m].weight]+knapsack[m].value;
	//else包括两种情况，共同点是该物体没有被使用
	else
	array[m][n]=array[m+1][n];
}

//往回找，确定某个物体i是否被使用
bool*Trace_back()
{
	int c=container;
	bool*used;
	used=(bool*)malloc(sizeof(bool)*(num+1));
	for(int i=1;i<num;i++)
	if(array[i][c]==array[i+1][c])
	used[i]=0;
	else
	{
	used[i]=1;
	c-=knapsack[i].weight;
	}
	used[num]=(c>=knapsack[num].weight)?1:0;
	return used;
}

//用来输出被使用的物体及其相关值
void Print_KnapSack(bool*used)
{
	printf("the objects used as follows:\n");
	for(int i=1;i<=num;i++)
	if(used[i])
	printf("%d:%d-%d\n",knapsack[i].object,knapsack[i].weight,knapsack[i].value);
}


int  main()
{
	bool*used;
	Create_KnapSack();
	Resolve_KnapSack();
	used=Trace_back();
	Print_KnapSack(used);
	return 0;
}