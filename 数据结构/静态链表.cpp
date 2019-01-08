#include<stdio.h>
#define Maxsize 100
typedef struct node
{
	int date;
	int next;
}SNode;
typedef struct Node
{
	SNode sp[Maxsize];
	int SL;
}StList,*PStList;
//在有些语言中比提供指针类型，就不能创建单链表
//用数组下标相对的表示地址称为静态指针或索引，这种链表叫做静态链表
int main()
{
	return 0;
}