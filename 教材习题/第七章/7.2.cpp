#include<stdio.h>
void xuanze(int a[],int n);
int main()
{
	int a[10]={98,15,54,23,16,31,90,15,45,67};
	int i;
	printf("before sorte:\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	
	xuanze(a,10);
	printf("\nafter sortde:\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
void xuanze(int a[],int n)
{
	int i,j,k,t;
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[k])
			{
				k=j;
			}
			if(k!=i)
			{
				t=a[i];
				a[i]=a[k];
				a[k]=t;	
			}
		}
	}
}