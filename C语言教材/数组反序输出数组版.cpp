#include<stdio.h>
void fanxu(int x[],int n);
int main()
{
	int i,a[5]={2,3,5,1,6};
	printf("the original array:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}	
	printf("\n");
	fanxu(a,5);
	
	printf("the array has been inverted:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
void fanxu(int x[],int n)
{
	int i,j,k;
	k=(n-1)/2;
	for(i=0;i<k;i++)
	{
		j=n-1-i;
		x[i]=x[i]+x[j];
		x[j]=x[i]-x[j];
		x[i]=x[i]-x[j];
	}
} 