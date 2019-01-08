#include<stdio.h>
int main()
{
	int *p[3];
	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	p[0]=a[0];
	p[1]=a[1];
	p[2]=a[2];
	for(int i=0;i<4;i++)
	{
		printf("%d\t",*(p[0]+i));
	}
	printf("\n");
	for(int i=0;i<4;i++)
	{
		printf("%d\t",*(p[1]+i));
	}
	printf("\n");
	for(int i=0;i<4;i++)
	{
		printf("%d\t",*(p[2]+i));
	}
	printf("\n");
} 