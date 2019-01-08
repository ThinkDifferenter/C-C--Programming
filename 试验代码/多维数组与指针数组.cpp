#include<stdio.h>
int main()
{
	int *p[3];
	int **q[3];
	int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	p[0]=a[0];
	p[1]=a[1];
	p[2]=a[2];
	q[0]=&p[0];
	q[1]=&p[1];
	q[2]=&p[2];
	printf("way 1:\n");
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
	printf("\n\nway 2:\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%d\t",*(*q[i]+j));
		}
		printf("\n");
	}
	printf("\n\nway 3:\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%d\t",*(*(a+i)+j));
		}
		printf("\n");
	}
	printf("\n");
	return 0;
} 