#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int num;
	double score;
	STU *next;
}STU;
int n;
STU *creat()
{
	STU *head;
	STU *p1,p2;
	n=0;
	p1=p2=(STU *)malloc(sizeof(STU));
	printf("input date:");
	scanf("%d %lf",&p1->num,&p1->score);
	head=NULL;
	while(p1->num!=0)
	{
		n++;
		if(n==1)
		{
			head=p1;
		}
		else
		{
			
		}
	}
}
int main()
{
		
}