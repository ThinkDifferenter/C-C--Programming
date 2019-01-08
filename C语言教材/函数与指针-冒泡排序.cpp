#include<stdio.h>
void maopao(int a[],int n);

int main()
{
	void (*p)(int a[],int n);
	p=maopao;
	int a[5]={2,4,8,9,3};
	
	p(a,5);
	
	for(int i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void maopao(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n;i++)
	{	
		for(j=n-i;j<n;j++)
		{
			if(a[j-1]>a[i])
			{
				t=a[i];
				a[i]=a[j-1];
				a[j-1]=t;
			}
		}
	}
}