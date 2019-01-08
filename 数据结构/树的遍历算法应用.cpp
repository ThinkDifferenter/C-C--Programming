#include<stdio.h>
#include<stdlib.h>
//������ʽ�洢��� 
typedef struct bnode
{
	char date;
	struct bnode *lchild,*rchild,*parent;	
}Bnode,*BTree;
//���������
void Visit(int n)
{
	printf("����������%d\n",n);
} 
//����������Ľ�����
//����һ�� �������򣨻����򣬺��򣩱����㷨�Ա������Ľ����м��� 
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
//����������һ�ö���������������������������������ɵ������֣������ܵĽ�������������ֽ����֮��
//�����Ľ������1����0��Ϊ��ʱ����������������������ķ��������ö������ķ���һ�������õݹ��㷨
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
//�����������ĸ߶�(������)
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
//�������ĸ���
//˼·���ȸ����������������Ƹ���㣬����ƶ������ĸ��ĵ�ַ
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
//������������洢�Ķ�����
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
//�������ÿ��Ľӵ���

int * Levcount_Tree(BTree t,int l,int num[])
//l�ǵ�ǰ�������Ĳ�����ÿ��Ľڵ�������num������ 
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