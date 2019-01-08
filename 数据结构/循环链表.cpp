#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int dete;
	struct node *next;
}LNode,*PLNode;
//两个循环链表的连接函数 
//r1,r2为要连接的两个循环链表的尾指针标识 
void DLinkList_Connet(PLNode r1,PLNode r2)//连接的函数操作的地址，所以不需要返回值！ 
{
	DLinkList p;
	p=r1->next;
	r1->next=r2->next->next;
	free(r2->next);
	r2->next=p;
}
int main()
{
	return 0;
}