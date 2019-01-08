#include<stdio.h>
#include<stdlib.h>
//������˳���ͬ������һ�ֶ�̬����Ĵ洢�ṹ��
//�����е�ÿ�����ռ�õĴ洢�ռ䲻��Ԥ�ȷ����
//����������ʱϵͳ�����������ɵ� 
typedef struct node
{
	int date;
	struct node *next;
}LNode,*LinkList;
//����ָ�������ָ�� 
LinkList head;
//��ʼ������ 
LinkList Creat_LinkList(void)
{
	LinkList H;
	H=(LinkList)malloc(sizeof(LNode));
	if(H)
	{
		H->next=NULL;
	}	
	return H;
} 
//�������� 
void Destroy_LinkList(LinkList *H)//����Ĳ���ֵ����ͷָ��ĵ�ַ������ 
{
	LinkList p,q;
	p=*H;
	while(p)
	{
		q=p;
		p=p->next;
		free(q);
	}
	*H=NULL;
}
//������ 
int Lenth_LinkList(LinkList H)
{
	LinkList p=H;
	int count =-1;
	while(p)
	{
		p=p->next;
		count++;
	}
	return count;
};
//����Ų��� 
LinkList Locate_LinkList(LinkList H,int i)
{
	LinkList p;
	int j;
	p=H;
	j=0;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j!=i||!p)//�������!p 
	{
		printf("not found in link list!\n");
		return NULL;
	}
	return p;
}
//�����ݲ���
LinkList Locate_LinkList_Value(LinkList H,int x)
{
	LinkList p=H->next;
	while(p&&p->date!=x)
	{
		p=p->next;
	}
	return p;
} 


int Insert_LinkList(LinkList H,int i,int x)
{
	LinkList q,p;
	p=Locate_LinkList(H,i-1);
	if(!p)
	{
		printf("the index is error!\n");
		return 0;
	}
	q=(LinkList)malloc(sizeof(LNode));
	if(!q)
	{
		printf("malloc error!\n");
		return 0;
	}
	//the key sentence!
	q->date=x;
	q->next=p->next;
	p->next=q;
	return 1;
}


int Delete_LinkList(LinkList H,int i)
{
	LinkList p,q;
	if(H==NULL||H->next==NULL)
	{
		printf("cannot delete the link list or the link lsit is empty!\n");
		return 0;
	}
	p=Locate_LinkList(H,i-1);
	if(p==NULL||p->next==NULL)
	{
		printf("index error!\n");
		return 0;
	}
	//the key sentence!
	q=p->next;//��Ҫɾ���Ľ��ָ���Լ������ö��һ�٣��� 
	p->next=q->next;
	free(q);
	return 1;
}


int main()
{
	return 0;
}
