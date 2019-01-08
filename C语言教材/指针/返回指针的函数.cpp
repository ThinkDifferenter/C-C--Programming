#include<stdio.h>
int *search(int (* p),int n);
int main()
{
	int score[][4]={{60,70,80,90},{56,89,67,88},{34,78,90,66}};
	int *p;
	int i,m;
	printf("enter the number of students:");
	scanf("%d",&m);
	printf("the scores of NO.%d are :\n",m);
	p=search(score,m);
	for(i=0;i<4;i++)
	{
		printf("%d\t",*(p+i));
	}
	printf("\n");
	return 0;	
}
int* search(int (*p)[4],int n)
{
	int *q;
	q=*(p+n);
	return q;	
}