#include<stdio.h>
void inv(int x[],int n);
int main()
{
	int i,a[10]={3,7,9,11,0,6,7,5,4,2};
	printf("The original array:\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	inv(a,10);
	printf("the array has been inverted:\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
void inv(int *x,int n)//ָ�봫���� 
{
	int tmp,*px+m,*i=x,*j=x+n-1,m=(n-1)/2;
	for(i<=p;i++,j--)
	{
		tmp=*i;
		*i=*j;
		*j=tmp;
	}
}
