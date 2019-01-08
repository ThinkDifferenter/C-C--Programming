#include<stdio.h>
int main()
{
	int a[10];
	int i,j,k,t;
	printf("Input 10 number:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n\n");
	
	printf("Show number:(before arrage)\n");
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n\n");
	for(i=0;i<10;i++)
	{
		for(j=10-i;j<10;j++)
		{
			if(a[j-1]>a[i])
			{
				t=a[j-1];
				a[j-1]=a[i];
				a[i]=t;
			}
		}
	}
	
	printf("Show number:(later arrange)");
	for(i=0;i<10;i++)
	{
		printf("%d\t",a[i]); 
	}
	printf("\n");
} 