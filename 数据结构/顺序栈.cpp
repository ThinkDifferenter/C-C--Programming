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
int main()
{
	return 0;	
}