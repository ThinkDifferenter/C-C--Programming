#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100  //���е�������� 
typedef struct queue 
{
	int date[MAXSIZE];
	int front;//���� 
	int rear;//��β 
} SeqQueue,*PSeqQueue;
//����һ��ָ����е�ָ��
PSeqQueue q=(PSeqQueue)malloc(sizeof(SeqQueue)); 
//���еĳ�ʼ��
PSeqQueue Init_SeqQueue()
{
	PSeqQueue q;
	q=(PSeqQueue)malloc(sizeof(SeqQueue));
	if(q)
	{
		q->front=0;
		q->rear=0;
	}	
	return q;
} 
//�ж϶ӿ�
int Empty_SeqQueue(PSeqQueue q)
{
	if(q&&q->front==q->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 
//���  �ڶ��еĺ�˲��� 
int In_SeqQueue(PSeqQueue q,int x)
{
	if((q->rear+1)%MAXSIZE==q->front)//���ѭ������ 
	{
		printf("The Queue is full!\n");
		return -1;
	} 
	else
	{
		q->rear=(q->rear+1)%MAXSIZE;
		q->date[q->rear]=x;
		return 1;
	}
} 
//���� �ڶ��е�ǰ�˲��� 
int Out_SeqQueue(PSeqQueue q,int *x)
{
	if(Empty_SeqQueue(q))
	{
		printf("Empty Queue!\n");
		return -1;
	}
	else
	{
		q->front=(q->front+1)%MAXSIZE;
		*x=q->date[q->front];
		return 1;
	}
} 
//��ȡ��ͷ������
int Front_SeqQueue(PSeqQueue q,int *x)
{
	if(Empty_SeqQueue(q))
	{
		printf("Empty Queue!\n");
		return -1;
	} 
	else{
		*x=q->date[(q->front+1)%MAXSIZE];
		return 1;
	}
} 
//���ٶ���
void Destroy_SeqQueue(PSeqQueue *q)//����һ��ָ�����ָ���ָ�� 
{
	if(*q)
	{
		free(*q);
	}
	*q=NULL;	
} 
int main()
{
	return 0;	
}