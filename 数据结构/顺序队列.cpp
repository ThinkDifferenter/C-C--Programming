#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100  //队列的最大容量 
typedef struct queue 
{
	int date[MAXSIZE];
	int front;//队首 
	int rear;//队尾 
} SeqQueue,*PSeqQueue;
//定义一个指向队列的指针
PSeqQueue q=(PSeqQueue)malloc(sizeof(SeqQueue)); 
//队列的初始化
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
//判断队空
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
//入队  在队列的后端操作 
int In_SeqQueue(PSeqQueue q,int x)
{
	if((q->rear+1)%MAXSIZE==q->front)//针对循环队列 
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
//出队 在队列的前端操作 
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
//读取队头的数据
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
//销毁队列
void Destroy_SeqQueue(PSeqQueue *q)//定义一个指向队列指针的指针 
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