#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct node
{
	int date[MAXSIZE];
	int lenth;
}Seqlist,*pSeqlist;
//定义一个指向顺序表的指针变量
pSeqlist PL; 
pSeqlist Init_Sequlist(void)
{
	pSeqlist PL;
	PL=(pSeqlist)malloc(sizeof(Seqlist));
	if(PL)
	{
		PL->lenth=0;
	}
	return PL;
}
int Lenth_Sequlist(Seqlist PL)
{
	return PL.lenth; 
}
int Location_Seqlist(Seqlist PL,int x)
{
	int i=0;
	int j;
	while(i<PL.lenth&&PL.date[i]!=x)
	{
		i++;
	}	
	if(i>=PL.lenth)
	{
		j=0;
	}
	else
	{
		j=i+1;
	}
	return j;
}
int Insert_Seqlist(pSeqlist PL,int i,int x)
{
	int j;
	if(!PL)
	{
		printf("the list is not found!\n");
		return -2;
	}
	if(PL->lenth>=MAXSIZE)
	{
		printf("the list is overflow!\n");
		return -1;
	}
	if(i<1||i>PL->lenth+1)
	{
		printf("the insert is not legal!\n");
		return 0;
	}
	for(j=PL->lenth-1;j>i-1;j--)//for(j=PL->lenth;j>i-1;j--)
	{
		PL->date[j+1]=PL->date[j];//PL->date[j+1]=PL->date[j];
	}
	PL->date[j-1]=x;
	PL->lenth++;
	return 1;
}
int Delete_Seqlist(pSeqlist PL,int i)
{
	int j;
	if(!PL)
	{
		printf("the list is not found!\n");
		return -1;
	}
	if(i<1||i>PL->lenth)
	{
		printf("the delete is not legal!\n");
		return 0;
	}
	for(j=i;j<PL->lenth;j++)//for(j=i;j<PL->lenth;j++)
	{
		PL->date[j-1]=PL->date[j];//PL->date[j-1]=PL->date[j];
	}
	PL->lenth--;
	return 1;
}
void Show_Seqlist(pSeqlist PL)
{
	for(int i=0;i<PL->lenth;i++)
	{
		printf("number %d element is %d\n",i+1,PL->date[i]);
	}	
}

int main()
{
	system("pause");
	return 0;
}
