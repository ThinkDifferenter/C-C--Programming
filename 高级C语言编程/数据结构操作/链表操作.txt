#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define H "-----------------------"

typedef  struct person
{
	char name[10];
	char addr[20];
	char tele[15];
	char qq[10];
	struct person *next;
} Person;

Person *head;

void linset(Person *p)
{
	Person *pa,*pb;
	pb=head;
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		while(pb)
		{
			pa=pb;
			pb=pb->next;
		}
		pa->next;
	} 
	p->next=NULL;
}

void lcreat()
{
	Person *pb;
	char ch;
	
	do
	{
		pb=(Person*)malloc(sizeof(Person));
		if(!pb)
		{
			printf("内存分配失败!\n!");
			exit(1);
		}
		printf("%s\n",H);
		printf("姓名:");
		gets(pb->name);
		
		printf("地址:");
		gets(pb->addr);
		
		printf("电话:");
		gets(pb->tele);
		
		printf("QQ:");
		gets(pb->qq);
		
		linset(pb);
		printf("\n继续输入下一人信息(y/n?):");
		ch=getchar();
		fflush(stdin);
	} while(ch=='y'||ch=='Y');
}


void ldisp()
{
	Person *pa;
	pa=head;
	while(pa)
	{
		printf("%s\n",H);
		printf("姓名:%s\n",pa->name);
		printf("地址:%s\n",pa->addr);
		printf("电话:%s\n",pa->tele);
		printf("QQ:%s\n",pa->qq);
		pa=pa->next;
	}
}
Person *lsearch(char *name)
{
	Person *pa;
	
	pa=head;
	while(pa)
	{
		if(strcmp(name,pa->name))
		{
			pa=pa->next;
		}
		else{
			return pa;
		}
	}
	return NULL;
}

void ldel(char *name)
{
	Person *pa,*pb;
	
	if(head==NULL)
	{
		printf("链表为空！\n");
		exit(1);
	}
	pb=head;
	while(strcmp(pb->name,name)&&pb->next)
	{
		pa=pb;
		pb=pb->next;
	}
	if(!strcmp(pb->name,name))
	{
		if(pb=head)
		{
			head=pb->next;
		}
		else
		{
			pa->next=pb->next;
		}
		free(pb);
	}
}
int main()
{
	Person *pf;
	char ch,name[10];
	
	head=NULL;
	
	do
	{
		printf("%s\n",H);
		printf("1-增加链表结点\n");
		printf("2-查找链表结点\n");
		printf("3-查看所有结点\n");
		printf("4-删除链表结点\n");
		printf("5-退出系统\n");
		ch=getchar();
		fflush(stdin);
		
		switch(ch)
		{
			case '1':
			{
				lcreat();
				break;
			}
			case '2':
			{
				printf("\n请输入查找姓名:");
				gets(name);
				
				pf=lsearch(name);
				if(pf==NULL)
				{
					printf("\n在链表中未找到%s的信息!\n",name);
				}
				else
				{
					printf("%s\n",H);
					printf("\n姓名:%s\n",pf->name);
					printf("地址:%s\n",pf->addr);
					printf("电话:%s\n",pf->tele);
					printf("QQ:%s\n",pf->qq);
					printf("%s\n",H);
				}
				break;
			}
			case '3':
			{
				ldisp();
				break;
			}
			case '4':
			{
				printf("\n请输入需要删除的姓名:");
				gets(name);
				
				ldel(name);
				break;
			}
			case '5':
			{
				exit(1);
			}
		} 
	}while(ch!='\0');
}