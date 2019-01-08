#include<stdio.h>
typedef struct student
{
	long int num;
	double score;
	struct student *next;
}STU;

//typedef struct student STU;

int main()
{
	int i=100;
	STU a,b,c,d;
	STU *head,*p;
	head=&a;
	p=head;
	a.num=0001;
	b.num=0002;
	c.num=0003;
	d.num=0004;
	a.score=90;
	b.score=91;
	c.score=92;
	d.score=93;
	a.next=&b;
	b.next=&c;
	c.next=&d;
	
	printf ("show link_list:\n");
	while(p->next!=NULL)
	{
		printf("NO.%d\tScore:%.2f\n",p->num,p->score);
		p=p->next;
	}
	printf("the sizeof struct is %d\n",sizeof(STU));
	return 0;	
}