#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct Stack
//˳��ջ�Ǿ�̬����洢��
//ջ�е�Ԫ�س�����ջ��������ռ�Ĵ�Сʱ����ջ�����---����
//ջ�е�Ԫ����Ҳû��Ԫ�س�ջʱ����ջ�����--���� 
{
	int date[MAXSIZE];//��������˵��ջû�����ޣ� 
	int top;//MAXSIZEֻ����Ϊ�Ĺ涨��������˳��� 
}SeqStack,*PSeqstack;
//����һ��ָ��˳��ջ��ָ��
PSeqstack s=(PSeqstack)malloc(sizeof(SeqStack)); 
//������ʽ�洢��� 
typedef struct bnode
{
	char date;
	struct bnode *lchild,*rchild,*parent;	
}Bnode,*BTree;
//ջ�ĳ�ʼ��
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
//�п�ջ
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
//��ջ
//x����������Ԫ�� 
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
//��ջ ��ɾ��ջ����Ԫ�� 
//ɾ��ջ����Ԫ�ر�����*x 
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
//ȡջ��Ԫ��
//ȡ����Ԫ�ط���*x��ջ�������ı� 
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
//����ջ->�ͷ��ڴ�
// Ҫ�޸�ջ��ָ����� �����Դ���ջ��ָ�� 
void Destroy_SeqStack(PSeqstack *s)//�������ָ��ĵ�ַ������ 
{
	if(*s)
	{
		free(*s);
	}
	*s=NULL;
} 
//���н�����ݵķ���
void Visit(int n)
{
	printf("����������%d\n",n);
} 
//��������ĵݹ��㷨
void PreOrder(BTree t)
{
	if(t)
	{
		Visit(t->date);//���ʽ�� 
		PreOrder(t->lchild);//���������� 
		PreOrder(t->rchild);//���������� 
	}	
} 
//����ջ����������ķǵݹ��㷨
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
			Push_SeqStack(s,p);//Ԥ��pָ����ջ�� 
			p=p->lchild; 
		} 
		else
		{
			Pop_SeqStack(s,&p);
			p=p->rchild;
		}
	}	
} 
//��������ĵݹ��㷨
void InOrder(BTree t)
{
	if(t)
	{
		InOrder(t->lchild)
		Visit(t->date);
		InOrder(t->rchild);
	} 
} 
//����ջ����������ķǵݹ��㷨
void INOrder(BTree t)
{
	PSeqstack s;
	BTree p=t;
	s=Init_SeqStack();
	while(p||!Empty_SeqStack(s))
	{
		if(p)
		{
			Push_SeqStack(s,p);//Ԥ��Pָ����ջ�� 
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
//��������ĵݹ��㷨
void PostOrder(BTree t)
{
	if(t)
	{
		PostOrder(t->lchild);
		PostOrder(t->rchild);
		Visit(t->date);
	}
} 
//����ջ�ĺ�������ķǵݹ��㷨
//����һ�� 
/*
������������ǵݹ鷽�����Զ��������ո����Һ��ӣ����ӵ�˳����з��ʣ����ʵ��Ľ����ʱ�����
���Ǳ��浽��һ��ջ�У������ʽ����󣬽���������ջ�еĽ��������ɡ� 
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
//���������ú���� 
/*
���ݶ��壬�����������������������֮����ʸ���㣬�����ڷǵݹ��㷨�У����������������������������ͬ
����������������ʱ����һ��㶼��һ�ν�ջ��һ�γ�ջ����������������У�����һ�γ�ջ�󣬻����ٴ���ջ
�����ܷ��ʵ�����Ҳ����˵�����Ҫ������ջ�����γ�ջ��������ӹ�������ڵڶ��γ�ջ����� 
*/ 
typedef struct
{
	Bnode *node;
	int flag;//0�����һ�ν���վ��1����ڶ��ν���ջ 
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