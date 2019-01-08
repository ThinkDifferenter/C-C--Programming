#include<stdio.h>
void xuanze(int a[],int n);

int main()
{
	void (*p)(int a[],int n);
	p=xuanze;
	int a[5]={2,4,8,9,3};
	
	p(a,5);
	
	for(int i=0;i<5;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
}
void xuanze(int a[],int n)
{
	int i,j,k,t;
	for(i=0;i<n;i++)
	{
		k=i;	
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[i])
			{
				k=i;
			}
			if(a[j]>a[k])
			{
				t=a[k];
				a[k]=a[j];
				a[j]=t;
			}
		}
	}
}