#include<stdio.h>
#include<stdlib.h>
struct student 
{
	int num;
	double score;
	struct student *next;
};
typedef struct student Stu;
int n;
Stu *creat_linklist()
{
	Stu *head;
	Stu *p1,*p2;//p1ǰ��ָ�룬p2���ָ�� 
	n=0;
	p1=p2=(Stu*)malloc(sizeof(Stu));
	printf("������%d��ͬѧ��ѧ�źͳɼ�:",n+1);
	scanf("%d %lf",&p1->num,&p1->score);
	head=NULL;
	while(p1->num!=0)
	{
		n++;
		if(n==1)
		{
			head=p1;
		}
		else
		{
			p2->next=p1;
		}
		p2=p1;
		p1=(Stu *)malloc(sizeof(Stu));//p1������һ���ڵ� 
		printf("������%d��ͬѧ��ѧ�źͳɼ�:",n+1);
		scanf("%d %lf",&p1->num,&p1->score);
	}
	p2->next=NULL;
	return head;
}
void print_linklist(Stu *head)
{
	Stu *p;
	printf("\nNow,These %d records are :\n",n);
	p=head;
	if(head!=NULL)
	{
		do
		{
			printf("ѧ��:%d   �ɼ�:%.2f\n",p->num,p->score);
			p=p->next; 
		}while(p!=NULL);
	} 
}
Stu *del_linklist(Stu *head,int num)
{
	Stu *p1,*p2;
	if(head==NULL)
	{
		printf("\nList NULL!\n");
		return head;
	}
	p1=head;
	while(num!=p1->num&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(num==p1->num)
	{
		if(p1==head)
		{
			head=p1->next;// ɾ��head(��һ���ڵ�) 
		}
		else
		{
			p2->next=p1->next;//ɾ��p2��ָ�Ľڵ� 
		}
		printf("delete:%d\n",num);
		n--;
	}
	else
	{
		printf("%d ����������!\n",num);
	} 
	return head;
} 
Stu *insert_linklist(Stu *head,Stu *insert)
{
	Stu *p0,*p1,*p2;
	p1=head;
	p0=insert;
	if(head==NULL)
	{
		head=p0;
		p0->next=NULL;
	} 
	else
	{
		while(p0->num>p1->num)
		{
			p2=p1;
			p1=p1->next;
			if(p0->num<=p1->num)
			{
				if(head==p1)
				{
					head=p0;
				}
				else
				{
					p2->next=p0;
					p0->next=p1;
				}
			}
			else
			{
				p1->next=p0;
				p0->next=NULL;
			}
		}
	}
	n++;
	return head;
} 
int main()
{
	Stu *head,stu;
	int del_num;
	
	printf("input records:\n");
	head=creat_linklist();
	print_linklist(head);
	printf("\ninput the deleted number :");
	scanf("%d",&del_num); 
	head=del_linklist(head,del_num);
	print_linklist(head);
	printf("\ninput the insrt record:");
	scanf("%d %lf",&stu.num,&stu.score);
	head=insert_linklist(head,&stu);
	print_linklist(head); 
	return 0;
}