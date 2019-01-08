#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int row,col;
	struct node *down,*right;
	union 
	{
		struct node *next;
		int value;
	};
}crosslist;
//行头结点和列头结点的row和col域值都为零，行头结点的right指针域指向该行链表的第一个结点,它的down指针为空 
//列头结点的down指针于指向该列链表的第一个结点，它的right指针为空
//所有的行，列链表和它们对应的行头结点和列头结点构成一个循环链表
//十字链表头结点的row和col域分存放稀疏矩阵的行数和列数，链表头结点的next指向行头结点的第一行头结点
//down和right指针指向NULL
crosslist *creatclinkmat()
{
	int m,n,t,k,i,j,v,s;
	crosslist *p,*q,*head,*cp[100];
	printf("请输入稀疏矩阵的行数:");
	scanf("%d",&m);
	printf("\n请输入稀疏矩阵的列数:");
	scanf("%d",&n);
	printf("\n请输入稀疏矩阵的非零元素的个数:");
	scanf("%d",&t);
	s=m>n?m:n;//确定行数和列数中的最大值 
	p=(crosslist *)malloc(sizeof(crosslist));
	p->row=m;
	p->col=n;
	head=p;
	cp[0]=p;//*cp[0....s]位一组指示头结点的行，列表头结点的指针 
	for(i=1;i<=s;i++)//建立头结点循环链表 
	{
		p=(crosslist *)malloc(sizeof(crosslist));
		p->row=0;
		p->col=0;
		cp[i]=p;
		p->right=p;
		p->down=p;
		cp[i-1]->next=p;
	}
	cp[s]->next=head;
	for(k=0;k<t;k++)
	{
		printf("输入一个非零元素的三元组(空格隔开):\n");
		scanf("%d %d %d",&i,&j,&v);
		p=(crosslist *)malloc(sizeof(crosslist));
		p->row=i;
		p->col=j;
		p->value=v;
		q=cp[i];
		while((q->right!=cp[i])&&(q->down->col<j))
		{
			q=q->down;//在行表中寻找行插入位置 
		}
		p->right=q->right;
		q->right=p;//完成第i行插入 
		q=cp[j];
		while((q->right!=cp[j])&&(q->down->row<i))
		{
			q=q->right;//在行表中寻找列插入位置 
		}
		p->down=q->down;
		q->down=p;//完成第j列插入 
	}
	return head;
} 
int main()
{
	return 0;	
}