#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int date;
	struct node *next;	
} LNode,*LinkList;
int main()
{
	LNode a,b,c;
	LinkList head;	
	a.date=11;
	b.date=12;
	c.date=13;
	head->next=&a;
	a.next=&b;
	b.next=&c;
	while(head->next!=NULL)
	{
		printf("%d",head->date);
		head=head->next;
	}
	return 0;
}