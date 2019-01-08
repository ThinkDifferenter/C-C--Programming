#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//创建一个链表
typedef struct node
{
	int date;
	struct node *next=NULL;	
}Node;

void bound(char ch,int n)
{
	while(n--)
	{
		putchar(ch);
	}
}

int main()
{
	Node *Head=NULL,*t,*End=NULL;
	int cnt=0;
	char choice;
	printf("开始创建链表:\n");
	do
	{
		cnt++;
		t=(Node *)malloc(sizeof(Node));
		printf("\n输入第%d个链表结点的数据:",cnt);
		scanf("%d",&t->date);
		getchar(); 
		printf("\n");
		bound('-',20);
		if(Head==NULL)
		{
			Head=t;
			End=t;
		}
		else
		{
			End->next=t;
			End=t;	
		}
		t->next=NULL;
		fflush(stdin);
		
		printf("\n还要输入结点数据吗？(y/n)");
		choice=getchar();
		if(choice!='y')
		{
			printf("\n结点数据输入结束!\n");
			break;	
		}
		
	}while(1);
	
	cnt=1;
	
	bound('-',20);
	printf("\n输入结点数据为:\n");
	while(Head)
	{
		printf("第%d个结点的数据为:%d\n",cnt,Head->date); 
		cnt++;
		Head=Head->next; 
	}
	
	return 0;	
}
