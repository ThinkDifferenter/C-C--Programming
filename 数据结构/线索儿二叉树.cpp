#include<stdio.h>
#include<stdlib.h>
/*在二叉树中常常会求解某结点在某次遍历次序下的前驱和后继结点，并且各结点在每种遍历次序下的前驱，
后继的差异较大。这种差异使得求解比较困难。
利用二叉链表中的空指针域，将二叉链表中的空指针域改为指向器前驱和后继，具体的说，就是讲二叉树的各节点
中的左孩子指针域改为指向其前驱，空的右孩子指针域改为指向其后继。这种新的指针为线索，
所得到的二叉树叫做线索二叉树。将二叉树变成线索二叉树的过程叫线索化。
线索二叉树根据所选择的次序可以分为先序，中序，后序线索二叉树。 
*/

typedef struct Threadnode
{
	int ltag,rtag;
	int date;
	struct Threadnode *lchild,*rchild;
}Threadnode,*ThreadTree;
/*ltag=0,lchild指向该结点的左孩子。 
  ltag=1.lchild指向该结点的前驱。 
  rtag=0,rchild指向该结点的右孩子。 
  rtag=1.rchild指向该结点的后继。
*/
//中序线索化（对一颗已经存储的 二叉树加线索）
void Visit(int n)
{
	printf("结点的数据为%d\n",n);
}
void InThread(ThreadTree t,ThreadTree Pre)
//递归中序线索化二叉树，指针变量pre指向t所指结点的前驱，函数调用前pre为空 
{
	if(t)
	{
		InThread(t->lchild,Pre);
		t->ltag=1;
		t->lchild=Pre;
	}
	if(t->rchild==NULL)
	{
		t->rtag=1;
	}
	if((Pre)&&(Pre->rtag==1))
	{
		Pre->rchild=t;
	}
	Pre=t;
	InThread(t->rchild,Pre);
}
//在终须二叉树上查找任意结点的中序后继结点 
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
//中序线索二叉树的遍历(非栈式)
void InOrderTh(ThreadTree t)
{
	ThreadTree p;
	if(t)
	{
		p=t;
		while(p->ltag==0)
		{
			p=p->lchild;
		}
		while(p)
		{
			Visit(p->date);
			p=InPostNode(p);//在中序线索二叉树上寻找结点p的中序后继结点 
		}
	}	
} 
 
int main()
{
	return 0;
}