#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int date;
	struct node *next;
}Qnode,*PQnode;
//��ʽ���еĽ��������Ľ��һ��
typedef struct Node
{
	PQnode front,rear;	
} LinkQueue,*PLinkQueue;
//��ͷβָ���װ��һ��
//����һ��ָ����е�ָ�� 
PLinkQueue q=(PLinkQueue)malloc(sizeof(LinkQueue));
//��ʼ���ն���
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
//�ж϶ӿ�
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
//��� �Ӷ��к������ 
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
		q->rear->next=p;//�����ǰ���һ������nextָ����ӵĽ��q 
		q->rear=p;//��βָ��ָ����е����һ�����q�����ӣ�		 
	}
	return 1;
} 
//���� �Ӷ�ǰ���� 
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
	q->front=q->front->next;//����ָ�����һλ 
	free(p);
	if(!q->front)//������q����ָ��ָ��NULL��ʱ��ִ��if��� 
	{
		q->rear=NULL;		
	} 
	return 1;
} 
//��ȡͷԪ��
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
//���ٶ���
void Destroy_LinkQueue(PLinkQueue *q)
{
	PQnode p;
	if(*q)//�����зǿյ�ʱ��ִ��if��� 
	{
		while(q->front)//��������ָ��ָ��ǿյ�ʱ��ִ��while��� 
		{
			p=q->front;
			q->front=q->front->next;
			free(p);//ʵ����free������q->frontָ�� 
		}
		free(*q);
	}
	*q=NULL;
} 
int main()
{
	return 0;
}