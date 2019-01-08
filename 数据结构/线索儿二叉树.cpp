#include<stdio.h>
#include<stdlib.h>
/*�ڶ������г��������ĳ�����ĳ�α��������µ�ǰ���ͺ�̽�㣬���Ҹ������ÿ�ֱ��������µ�ǰ����
��̵Ĳ���ϴ����ֲ���ʹ�����Ƚ����ѡ�
���ö��������еĿ�ָ���򣬽����������еĿ�ָ�����Ϊָ����ǰ���ͺ�̣������˵�����ǽ��������ĸ��ڵ�
�е�����ָ�����Ϊָ����ǰ�����յ��Һ���ָ�����Ϊָ�����̡������µ�ָ��Ϊ������
���õ��Ķ�������������������������������������������Ĺ��̽���������
����������������ѡ��Ĵ�����Է�Ϊ�������򣬺��������������� 
*/

typedef struct Threadnode
{
	int ltag,rtag;
	int date;
	struct Threadnode *lchild,*rchild;
}Threadnode,*ThreadTree;
/*ltag=0,lchildָ��ý������ӡ� 
  ltag=1.lchildָ��ý���ǰ���� 
  rtag=0,rchildָ��ý����Һ��ӡ� 
  rtag=1.rchildָ��ý��ĺ�̡�
*/
//��������������һ���Ѿ��洢�� ��������������
void Visit(int n)
{
	printf("��������Ϊ%d\n",n);
}
void InThread(ThreadTree t,ThreadTree Pre)
//�ݹ�������������������ָ�����preָ��t��ָ����ǰ������������ǰpreΪ�� 
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
//������������ϲ���������������̽�� 
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
//���������������ı���(��ջʽ)
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
			p=InPostNode(p);//������������������Ѱ�ҽ��p�������̽�� 
		}
	}	
} 
 
int main()
{
	return 0;
}