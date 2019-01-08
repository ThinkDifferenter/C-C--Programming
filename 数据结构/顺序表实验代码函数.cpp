#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int main()
{
	;
}
int Insert(int *a,int index,int n)
{
	int i;
	if(!a)
	{
		printf("the list is not found!\n");
		return -1;
	}	
	if(index<1||index>MAXSIZE)
	{
		printf("the operator is not legal!\n");
		return -2;
	}
	for(i=MAXSIZE;i>index-1;i--)
	{
		a[i+1]=a[i];
	}
	a[index-1]=n;
	return 0;
}
int Delete(int *a,int index)
{
	int i;
	if(!a)
	{
		printf("the list is not found!\n");
		return -1;
	}	
	if(index<1||index>MAXSIZE)
	{
		printf("the operator is not legal!\n");
		return -2;
	}
	for(i=index;i<MAXSIZE;i++)
	{
		a[i-1]=a[i];
	}	
	return 0;
}