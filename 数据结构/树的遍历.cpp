#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct Stack
//顺序栈是静态分配存储的
//栈中的元素超过给栈分配的最大空间的大小时产生栈的溢出---上溢
//栈中的元素再也没有元素出栈时产生栈的溢出--下溢 
{
	int date[MAXSIZE];//按理论来说，栈没有上限！ 
	int top;//MAXSIZE只是人为的规定，区别于顺序表！ 
}SeqStack,*PSeqstack;
//定义一个指向顺序栈的指针
PSeqstack s=(PSeqstack)malloc(sizeof(SeqStack)); 
//树的链式存储结点 
typedef struct bnode
{
	char date;
	struct bnode *lchild,*rchild,*parent;	
}Bnode,*BTree;
//栈的初始化
PSeqstack Init_SeqStack(void)
{
	PSeqstack s;
	s=(PSeqstack)malloc(sizeof(SeqStack));
	if(s)
	{
		s->top=-1;
	}
	return s;
} 
//判空栈
int Empty_SeqStack(PSeqstack s)
{
	if(s->top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 
//入栈
//x代表插入的新元素 
int Push_SeqStack(PSeqstack s,int x)
{
	if(s->top==MAXSIZE-1)
	{
		return 0;	
	}
	else
	{
		s->top++;
		s->date[s->top]=x;
		return 1;
	}
} 
//出栈 即删除栈顶的元素 
//删除栈顶的元素保留在*x 
int Pop_SeqStack(PSeqstack s,int *x)
{
	if(Empty_SeqStack(s))
	{
		return 0;
	}	
	else
	{
		*x=s->date[s->top];
		s->top--;
		return 1; 
	}
} 
//取栈顶元素
//取出的元素放在*x，栈不发生改变 
int Get_SeqStack(PSeqstack s,int *x)
{
	if(Empty_SeqStack(s))
	{
		return 0;
	}	
	else
	{
		*x=s->date[s->top];
		return 1;
	}
} 
//销毁栈->释放内存
// 要修改栈的指针变量 ，所以传入栈的指针 
void Destroy_SeqStack(PSeqstack *s)//传入的是指针的地址！！！ 
{
	if(*s)
	{
		free(*s);
	}
	*s=NULL;
} 
//树中结点数据的访问
void Visit(int n)
{
	printf("结点的数据是%d\n",n);
} 
//先序遍历的递归算法
void PreOrder(BTree t)
{
	if(t)
	{
		Visit(t->date);//访问结点 
		PreOrder(t->lchild);//遍历左子树 
		PreOrder(t->rchild);//遍历右子树 
	}	
} 
//利用栈的先序遍历的非递归算法
void PREOrder(BTree t)
{
	PSeqstack s;
	BTree p=t;
	s=Init_SeqStack();
	while(p||!Empty_SeqStack(s))
	{
		if(p)
		{
			Visit(p->date);
			Push_SeqStack(s,p);//预留p指针在栈中 
			p=p->lchild; 
		} 
		else
		{
			Pop_SeqStack(s,&p);
			p=p->rchild;
		}
	}	
} 
//中序遍历的递归算法
void InOrder(BTree t)
{
	if(t)
	{
		InOrder(t->lchild)
		Visit(t->date);
		InOrder(t->rchild);
	} 
} 
//利用栈的中序遍历的非递归算法
void INOrder(BTree t)
{
	PSeqstack s;
	BTree p=t;
	s=Init_SeqStack();
	while(p||!Empty_SeqStack(s))
	{
		if(p)
		{
			Push_SeqStack(s,p);//预留P指针在栈中 
			p=p->lchild;
		}
		else
		{
			Pop_SeqStack(s,&p);
			Visit(p->date);
			p=p->rchild;
		}
	}
} 
//后序遍历的递归算法
void PostOrder(BTree t)
{
	if(t)
	{
		PostOrder(t->lchild);
		PostOrder(t->rchild);
		Visit(t->date);
	}
} 
//利用栈的后序遍历的非递归算法
//方法一： 
/*
利用先序遍历非递归方法，对二叉树按照根，右孩子，左孩子的顺序进行访问，访问到的结点暂时不输出
而是保存到另一个栈中，待访问结束后，将被保存在栈中的结点输出即可。 
*/ 
void POstOrder(BTree t)
{
	PSeqstack s1,s2;
	BTree p=t;
	s1=Init_SeqStack();
	s2=Init_SeqStack();
	while(p||!Empty_SeqStack(s2))
	{
		if(p)
		{
			Push_SeqStack(s1,p);
			Push_SeqStack(s2,p);
			p=p->rchild;
		}
		else
		{
			Pop_SeqStack(s2,&p);
			p=p->lchild;
		}
	}	
	while(!Empty_SeqStack(s1))
	{
		Pop_SeqStack(s1,&p);
		Visit(p->date);
	}
}
//方法二：好好理解 
/*
根据定义，后序遍历是在左右子树遍历之后访问根结点，所以在非递归算法中，后序遍历与先序遍历或中序遍历不同
先序遍历或中序遍历时，任一结点都是一次进栈，一次出栈，而后序遍历过程中，结点第一次出栈后，还需再次入栈
否则不能访问到根。也就是说，结点要两次入栈，两次出栈，而处理加工结点是在第二次出栈后进行 
*/ 
typedef struct
{
	Bnode *node;
	int flag;//0代表第一次进出站，1代表第二次进出栈 
}DateType;

void POSTOrder(BTree t)
{
	PSeqstack s;
	DateType Sq;
	BTree p=t;
	s=Init_SeqStack();
	while(p||!Empty_SeqStack(s))
	{
		if(p)
		{
			Sq.flag=0;
			Sq.node=p;
			Push_SeqStack(s,Sq);
			p=p->lchild;
		}
		else
		{
			Pop_SeqStack(s,&Sq);
			p=Sq.node;
			if(flag==0)
			{
				Sq.flag=1;
				Push_SeqStack(s,Sq);
				p=p->rchild;
			}
			else
			{
				Visit(p->date);
				p=NULL;
			}
		}
	}
}
int main()
{
	return 0;	
}