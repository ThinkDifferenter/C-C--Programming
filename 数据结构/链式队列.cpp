#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int date;
	struct node *next;
}Qnode,*PQnode;
//链式队列的结点与链表的结点一样
typedef struct Node
{
	PQnode front,rear;	
} LinkQueue,*PLinkQueue;
//将头尾指针封装在一起
//定义一个指向队列的指针 
PLinkQueue q=(PLinkQueue)malloc(sizeof(LinkQueue));
//初始化空队列
PLinkQueue Init_LinkQueue()
{
	PLinkQueue q;
	q=q=(PLinkQueue)malloc(sizeof(LinkQueue));
	if(q)
	{
		q->front=0;
		q->rear=0;
	}
	return q;
}
//判断队空
int Empty_LinkQueue(PLinkQueue q)
{
	if(q&&q->front==NULL&&q->rear==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 
//入队 从队列后面操作 
int In_LinkQueue(PLinkQueue q,int x)
{
	PQnode p;
	p=(PQnode)malloc(sizeof(Qnode));
	if(!p)
	{
		printf("Queue is overflowed!\n");
		return 0;
	} 
	p->date=x;
	p->next=NULL;
	if(Empty_LinkQueue(q))
	{
		q->front=q->rear=p;
	}
	else
	{
		q->rear->next=p;//让入队前最后一个结点的next指向入队的结点q 
		q->rear=p;//让尾指针指向队列的最后一个结点q完成入队！		 
	}
	return 1;
} 
//出队 从队前操作 
int Out_LinkQueue(PLinkQueue q,int *x)
{
	PQnode p;
	if(Empty_LinkQueue(q))
	{
		printf("Empty Queue!\n");
		return 0;
	}
	*x=q->front->date;
	p=>q->front;
	q->front=q->front->next;//队首指针后移一位 
	free(p);
	if(!q->front)//当队列q的首指针指向NULL的时候执行if语句 
	{
		q->rear=NULL;		
	} 
	return 1;
} 
//读取头元素
int Front_LinkQueue(PLinkQueue q,int *x)
{
	if(Empty_LinkQueue(q))
	{
		printf("Empty Queue!\n");
		return 0;
	} 
	*x=q->front->date;
	return 1;
} 
//销毁队列
void Destroy_LinkQueue(PLinkQueue *q)
{
	PQnode p;
	if(*q)//当队列非空的时候执行if语句 
	{
		while(q->front)//当队列首指针指向非空的时候执行while语句 
		{
			p=q->front;
			q->front=q->front->next;
			free(p);//实际上free掉的是q->front指针 
		}
		free(*q);
	}
	*q=NULL;
} 
int main()
{
	return 0;
}