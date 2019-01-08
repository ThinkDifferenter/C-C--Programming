#include<stdio.h>
typedef struct student
{
	int num;
	double score;
	student *next;
}Stu;
int main()
{
	Stu a,b,c;
	Stu *head;
	a.num=10101;a.score=89.5;
	b.num=10103;b.score=90.0;
	c.num=10107;c.score=85.0;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	do
	{
		printf("num=%d,score=%.2f\n",head->num,head->score);
		head=head->next;
	}while(head!=NULL);	
	return 0;	
}