#include<stdio.h>
#include<stdlib.h>
typedef struct Threadnode
{
	int ltag,rtag;
	int date;
	struct Threadnode *lchild,*rchild;
} Threadnode,*ThreadTree;
//�����������������ϲ��������������ǰ�����
ThreadTree InPreNode(ThreadTree p)
//������������������Ѱ�ҽ��p������ǰ����㣬����p�ǿ� 
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
//�����������������ϲ���������������̽��
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
//�����������������ϲ���ֵΪx�Ľ��
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
//�����������������ϵĲ���
void InsertThrRight(ThreadTree s,ThreadTree p) 
//������������в�����pʹ���Ϊ���s���Һ��ӣ�p�Ǵ�����Ľ���ָ�� 
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
		//��sԭ��������������ʱ���ҵ�s�ĺ��w����wΪp�ĺ�̣�pΪw��ǰ�� 
		w=InPostNode(p);
		w->lchild=p;
	}	
}