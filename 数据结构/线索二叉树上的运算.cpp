#include<stdio.h>
#include<stdlib.h>
typedef struct Threadnode
{
	int ltag,rtag;
	int date;
	struct Threadnode *lchild,*rchild;
} Threadnode,*ThreadTree;
//在中序线索二叉树上查找任意结点的中序前驱结点
ThreadTree InPreNode(ThreadTree p)
//在中序线索二叉树上寻找结点p的中序前驱结点，假设p非空 
{
	ThreadTree pre;
	pre=p->lchild;
	if(p->ltag==1)
	{
		return pre;
	}
	else
	{
		while(pre->rtag==0)
		{
			pre=pre->rchild;
		}
	}
	return pre;
} 
//在中序线索二叉树上查找任意结点的中序后继结点
ThreadTree InPostNode(ThreadTree p)
{
	ThreadTree post;
	post=p->rchild;
	if(p->rtag==1)
	{
		return post;
	}
	else
	{
		while(post->ltag==0)
		{
			post=post->lchild;
		}
	}
	return post;
} 
//在中序线索二叉树上查找值为x的结点
ThreadTree Search(ThreadTree t,int x)
{
	ThreadTree p;
	p=t;
	if(p)
	{
		while(p->ltag==0)
		{
			p=p->lchild;
		}
		while(p&&p->date!=x)
		{
			p=InPostNode(p);	
		}
	}
	return p;
} 
//在中序线索二叉树上的插入
void InsertThrRight(ThreadTree s,ThreadTree p) 
//在中序二叉树中插入结点p使其成为结点s的右孩子，p是待插入的结点的指针 
{
	ThreadTree w;
	p->rchild=s->rchild;
	p->rtag=s->rtag;
	p->lchild=s;
	p->ltag=1;
	s->rchild=p;
	s->rtag=0;
	if(p->rtag==0)
	{
		//当s原来的右子树不空时，找到s的后继w，变w为p的后继，p为w的前驱 
		w=InPostNode(p);
		w->lchild=p;
	}	
}