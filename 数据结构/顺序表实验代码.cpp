#include<stdio.h>
int Insert(int *a,int index,int n);
int Delete(int *a,int index);
int main()
{
	int a[10];
	int i;
	for(i=0;i<10;i++)
	{
		a[i]=i+1;
		printf("%d\t",a[i]);
	}
	Delete(a,5);
	for(i=0;i<9;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	Insert(a,6,12);
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);	
	}
	printf("\n");
	return 0;
}
int Insert(int *a,int index,int n)
{
	int i;
	if(!a)
	{
		printf("the array is not found!\n");
		return -2;
	}
	if(index<1||index>10)
	{
		printf("the operator is not legal!\n");
		return -1;
	}
	for(i=10;i>index-1;i--)
	//for(i=index-1;i<10;i++)//error!�Ӳ��봦�ƶ��Ὣ���봦�Ժ��Ԫ�ض����ǵ� 
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
		printf("the array is not found!\n");
		return -2;
	}
	if(index<1||index>10)
	{
		printf("the operator is not legal!\n");
		return -1;
	}
	for(i=index;i<10;i++)
	//for(i=10;i>index;i--)error!ɾ��֮����±�һ�����Ǵ����ʼ�ģ� 
	{
		a[i-1]=a[i];
	}
	return 0;
}