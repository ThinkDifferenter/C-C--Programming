#include<stdio.h>
void xuanze(int *a,int n);
int main()
{
	int a[10],*p=a,i;
	printf("input array:\n");
	for(i=0;i<10;i++,p++)
	{
		scanf("%d",*p);
	}
	p=a;
	xuanze(a,10);
	
	printf("show array:\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",*p++);
	}
}
void xuanze(int *a,int n)
{
	int i,j,k,t;
	for(i=0;i<10;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(*(a+j)>*(a+k))  k=j;
			if(k!=i)
			{
				t=*(a+i);
				*(a+i)=*(a+k);
				*(a+j)=t;
			}
		}
	}
}