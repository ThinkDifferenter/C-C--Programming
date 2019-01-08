#include<stdio.h>
int main()
{
	int a[2][2];
	int i,j;
	int *p=*a;
	int (*q)[2]=a;
	printf("input array:\n");
	for(i=0;i<4;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n1. show array:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
	printf("\n2. show array:\n");
	for(i=0;i<4;i++)
	{
		if(i%2==0)
		{
			printf("\n");
		}
		printf("%d",*(a+i));	
	}
	
	return 0;
}