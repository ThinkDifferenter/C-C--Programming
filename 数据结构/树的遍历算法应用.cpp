#include<stdio.h>
#include<stdlib.h>
//树的链式存储结点 
typedef struct bnode
{
	char date;
	struct bnode *lchild,*rchild,*parent;	
}Bnode,*BTree;
//访问数结点
void Visit(int n)
{
	printf("结点的数据是%d\n",n);
} 
//计算二叉树的结点个数
//方法一： 是在中序（或先序，后序）遍历算法对遍历到的结点进行计数 
int  Count_Tree(BTree t)
{
	int cnt=0;
	if(t)
	{
		Count_Tree(t->lchild);
		Visit(t->date);
		cnt++; 
		Count_Tree(t->rchild);	
	}
	return cnt;
} 
//方法二：将一棵二叉树看成由树根，左子树和右子树组成的三部分，所以总的结点树是这三部分结点树之和
//树根的结点数是1或者0（为空时），而求左右子树结点数的方法和整棵二叉树的方法一样。可用递归算法
int COunt_Tree(BTree t)
{
	int lcnt=0,rcnt=0;
	if(t==NULL)
	{
		return 0;
	}
	lcnt=COunt_Tree(t->lchild);
	rcnt=COunt_Tree(t->rchild);
	return (lcnt+rcnt+1);
} 
//计数二叉树的高度(即层数)
int Heigh_Tree(BTree t)
{
	int h1=0,h2=0;
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		h1=Heigh_Tree(t->lchild);
		h2=Heigh_Tree(t->rchild);
		if(h1>h2)
		{
			return h1+1;
		}
		return h2+1;
	}
} 
//二叉树的复制
//思路：先复制左右子树，后复制根结点，最后复制二叉树的根的地址
BTree Copy_Tree(BTree t)
{
	BTree p,q,s;
	if(t==NULL)
	{
		return NULL;
	}
	p=Copy_Tree(t->lchild);
	q=Copy_Tree(t->rchild);
	s=(Bnode *)malloc(sizeof(Bnode));
	s->date=t->date;
	s->lchild=p;
	s->rchild=q;
	return s;
} 
//创建二叉链表存储的二叉树
BTree CreatBinTree()
{
	BTree t;
	char ch;
	ch=getchar();
	if(ch=='#')
	{
		t=NULL;
	}
	else
	{
		t=(Bnode *)malloc(sizeof(Bnode));
		t->date=ch;
		t->lchild=CreatBinTree();
		t->rchild=CreatBinTree();
	}
	return t;
} 
//求二叉树每层的接点数

int * Levcount_Tree(BTree t,int l,int num[])
//l是当前二叉树的层数，每层的节点数放在num数组中 
{
	if(t)
	{
		Visit(t->date);
		num[l]++;
		Levcount_Tree(t->lchild,l+1,num);
		Levcount_Tree(t->rchild,l+1,num);
	} 
	return (num);
} 