#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct
{
	int object;
	int weight;
	int value;
}KnapSack;

KnapSack * knapsack;//�������飬��malloc��new��̬����
int num;//����ĸ���
int container;//�������������
int**array=NULL;//�������������Ľ��

//��̬��������
void Create_KnapSack()
{
	//�ļ����� 
	FILE *fp;
	int Val = 0;
	char FileName[1024] = "";
	
	sprintf(FileName, "knapsack16-.txt");
	if ((fp=fopen(FileName,"r"))==NULL)
	{   
		//��ȡ�ļ�ʧ��
		printf("The file is not found");
		exit(0); 
	}
	
	//������Ʒ����
	fscanf(fp,"%d",&Val);
	int m_Dim = Val;
	num=m_Dim;
	knapsack=(KnapSack *)malloc(sizeof(KnapSack)*(num+1));
	
	//����ڴ��ݻ�
	fscanf(fp,"%d",&Val);
	int m_Contain = Val;
	container=m_Contain;
//	printf("�ڴ����ݻ�Ϊ:%.2f\n",m_Contain);
	
//	printf("\n\n----��ֵ:\n");
	//����ÿ����Ʒ�ļ�ֵ
	for (int j=1; j<=num; j++)
	{
		fscanf(fp,"%d",&Val);
		knapsack[j].object=j;
		knapsack[j].value = Val;
		//printf("%.2f\t", Val);
	}

//	printf("\n\n----���:\n");
	//����ÿ����Ʒ�����
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
//		getchar();//Ϊ�˻�ȡ�ո����������
//	}
//	int k=knapsack[num].value;
//	printf("%d\n",k);
//	printf("input the volume of the knapsack:\n");
	
}

//ȷ������������
void Resolve_KnapSack()
{
	int k=knapsack[num].value;
	printf("%d",k);
	//������̬��ά����m[num][container]
	array=(int**)malloc((num+1)*sizeof(int*));
	for(int i=0;i<=num;i++)
	array[i]=(int*)malloc((container+1)*sizeof(int));
	//
	for(int j=0;j<=container;j++)
	array[num][j]=(j>=knapsack[num].weight)?knapsack[num].value:0;
	//����������Ž��
	for(int m=num-1;m>0;m--)
	for(int n=0;n<=container;n++)
	if(n>knapsack[m].weight&&array[m+1][n]<=array[m+1][n-knapsack[m].weight]+knapsack[m].value)
	array[m][n]=array[m+1][n-knapsack[m].weight]+knapsack[m].value;
	//else���������������ͬ���Ǹ�����û�б�ʹ��
	else
	array[m][n]=array[m+1][n];
}

//�����ң�ȷ��ĳ������i�Ƿ�ʹ��
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

//���������ʹ�õ����弰�����ֵ
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