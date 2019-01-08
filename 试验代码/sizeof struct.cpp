#include<stdio.h>
typedef struct  
{
	int num;
	double score;	
} STU;
int main()
{
	STU a;
	STU *p;
	p=&a;
	a.num=1001;
	a.score=99.9;
	printf("sizeof (STU) is %d\n",sizeof(STU));
	printf("sizeof (a.num) is %d\n",sizeof(a.num));
	printf("sizeof (a.score) is %d\n",sizeof(a.score));
	printf("sizeof (a) is %d\n",sizeof(a));
	printf("num:%d\tscore:%.2f\n",p->num,p->score);
	printf("num:%d\tscore:%.2f\n",a.num,a.score);
	return 0;
}