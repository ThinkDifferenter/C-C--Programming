#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 256
typedef struct node
{
	char date[MAXSIZE];
	struct node *next;
}LinkString;
typedef struct Node
{
	LinkString *head,*tail;//定义串的头指针和为指针 
	int curlen;//当前字符串链表的长度 
}Lstring;
int main()
{
	return 0;	
}