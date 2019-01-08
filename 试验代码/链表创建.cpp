#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����һ������
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
	printf("��ʼ��������:\n");
	do
	{
		cnt++;
		t=(Node *)malloc(sizeof(Node));
		printf("\n�����%d�������������:",cnt);
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
		
		printf("\n��Ҫ������������(y/n)");
		choice=getchar();
		if(choice!='y')
		{
			printf("\n��������������!\n");
			break;	
		}
		
	}while(1);
	
	cnt=1;
	
	bound('-',20);
	printf("\n����������Ϊ:\n");
	while(Head)
	{
		printf("��%d����������Ϊ:%d\n",cnt,Head->date); 
		cnt++;
		Head=Head->next; 
	}
	
	return 0;	
}
