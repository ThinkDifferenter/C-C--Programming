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
	LinkString *head,*tail;//���崮��ͷָ���Ϊָ�� 
	int curlen;//��ǰ�ַ�������ĳ��� 
}Lstring;
int main()
{
	return 0;	
}