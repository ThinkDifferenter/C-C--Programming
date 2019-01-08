#include<stdio.h>
#include<stdlib.h>
//链表与顺序表不同，它是一种动态管理的存储结构，
//链表中的每个结点占用的存储空间不是预先分配的
//而是与运行时系统根据需求生成的 
typedef struct node
{
	int date;
	struct node *next;
}LNode,*LinkList;
//定义指向链表的指针 
LinkList head;
//初始化链表 
LinkList Creat_LinkList(void)
{
	LinkList H;
	H=(LinkList)malloc(sizeof(LNode));
	if(H)
	{
		H->next=NULL;
	}	
	return H;
} 
//销毁链表 
void Destroy_LinkList(LinkList *H)//传入的参数值链表头指针的地址！！！ 
{
	LinkList p,q;
	p=*H;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
	*H=NULL;
}
//链表长度 
int Lenth_LinkList(LinkList H)
{
	LinkList p=H;
	int count =-1;
	while(p)
	{
		p=p->next;
		count++;
	}
	return count;
};
//按序号查找 
LinkList Locate_LinkList(LinkList H,int i)
{
	LinkList p;
	int j;
	p=H;
	j=0;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j!=i||!p)//不能理解!p 
	{
		printf("not found in link list!\n");
		return NULL;
	}
	return p;
}
//按数据查找
LinkList Locate_LinkList_Value(LinkList H,int x)
{
	LinkList p=H->next;
	while(p&&p->date!=x)
	{
		p=p->next;
	}
	return p;
} 


int Insert_LinkList(LinkList H,int i,int x)
{
	LinkList q,p;
	p=Locate_LinkList(H,i-1);
	if(!p)
	{
		printf("the index is error!\n");
		return 0;
	}
	q=(LinkList)malloc(sizeof(LNode));
	if(!q)
	{
		printf("malloc error!\n");
		return 0;
	}
	//the key sentence!
	q->date=x;
	q->next=p->next;
	p->next=q;
	return 1;
}


int Delete_LinkList(LinkList H,int i)
{
	LinkList p,q;
	if(H==NULL||H->next==NULL)
	{
		printf("cannot delete the link list or the link lsit is empty!\n");
		return 0;
	}
	p=Locate_LinkList(H,i-1);
	if(p==NULL||p->next==NULL)
	{
		printf("index error!\n");
		return 0;
	}
	//the key sentence!
	q=p->next;//让要删除的结点指向自己（觉得多此一举！） 
	p->next=q->next;
	free(q);
	return 1;
}


int main()
{
	return 0;
}
