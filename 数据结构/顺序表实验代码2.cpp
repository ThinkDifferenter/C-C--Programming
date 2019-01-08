#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct Seqlist
{
	int date[MAXSIZE];
	int lenth;
}SeqList,*PSeqlist;
int Insert_Seqlist(PSeqlist PL,int index,int x)
{
	int i;
	if(!PL)
	{
		printf("the list is empty!\n");
		return -2;
	}	
	if(PL->lenth>=MAXSIZE)
	{
		printf("the list is overflow!\n");
		return -1;
	}
	if(index<1||index>PL->lenth+1)
	{
		printf("the insert operator is not legal!\n");
		return 0;
	}
	for(i=PL->lenth-1;i>=index-1;i--)//Àí½âi>=index! 
	{
		PL->date[i+1]=PL->date[i];
	}
	PL->date[index-1]=x;
	PL->lenth++;
	return 1;
}
int Delete_Seqlist(PSeqlist PL,int index)
{
	int i;
	if(!PL)
	{
		printf("the list is empty!\n");
		return -1;
	}
	if(index<1||index>PL->lenth+1)
	{
		printf("the delete operator is not legal!\n");
		return 0;
	}
	for(i=index;i<PL->lenth;i++)
	{
		PL->date[i-1]=PL->date[i];
	}
	PL->lenth--;
	return 1;
}

int main()
{	
	return 0;	
}