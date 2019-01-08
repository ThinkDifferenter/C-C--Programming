#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int date;
	struct node *prior,*next;
}DuNode,*DLinkList;
 //p是指向双向循环链表中的某一结点，即p是该结点的指针 
 //则p->prior->next表示*p结点之前驱结点的后继结点的指针,即与p相等 
 //则p->next->prior表示*p结点之后继结点的前驱结点的指针,即与p相等
 //p->prior->next==p->next->prior
 
  
 //双向链表的插入函数 
 //p指向双链表中某结点 
 //s指向待插入的值为x的新结点
 //将*s插入到 *p的前面 
  
 void DLinkList_Insert(DLinkList p,DLinkList s)
 {
 	s->prior=p->prior;//s的前驱指针指向结点P前一个结点
 	p->prior->next=s;// 结点p前一个结点的后继指针指向s结点 
 	s->next=p;
 	p->prior=s;
 	return s;
 } 
 //删除双向链表的函数 
 void DLinkList_Delete(DLinkList p)
 {
 	p->prior->next=p->next;// 结点*p的前一个结点的后继指针指向结点*P后一个结点的前驱指针 
 	p->next->prior=p->prior;//结点*p的后一个结点的前驱指针指向结点*P前一个结点的后继指针  
 	free(p);
 } 
int main()
{
	return 0;
}
 