#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 256
//带串长度的索引器 
typedef struct node
{
	char name[MAXSIZE];
	int lenth;
	char *stradr;//串的起始地址 
}LNode;
//末尾指针的索引器 
typedef struct Node
{
	char name[MAXSIZE];
	char *stradr,*enadr;
}ENode; 
typedef struct NOde
{
	int length;
	int stradr;
}Hstring;

int main()
{
	
} 