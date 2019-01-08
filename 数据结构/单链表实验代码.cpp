#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int date;
	char ch;
	char str[100];
	struct node *next;
}LNode,*PLNode;

int main()
{
	LNode a,b,c;
	PLNode h;//-->LNode *h;
	a.date=10;
	a.ch='w';
	a.str="jiangjun";	
}