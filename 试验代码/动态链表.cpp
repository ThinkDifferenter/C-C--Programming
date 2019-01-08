#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student//student node
{
	int no;
	char name[10];
	char sex[3];
	int age;
	char mobile[13];
	char QQ[13];
	char address[80];
	struct student *next;
}STU;

void bound(char ch,int n)
{
	while(n--)
	{
		putchar(ch);
	}
}
int main()
{
	STU stu;
	STU *H=&stu,*Tstu;
	char choice;
	int cnt=1,i=0;
	printf("输入第1个同学信息:\n");
	bound('-',20);
		printf("\n姓名:");
		scanf("%s",stu.name);//gets(stu.name);
		
		printf("学号:");
		scanf("%d",&stu.no);
		
		printf("年龄:");
		scanf("%d",&stu.age);
		
		printf("性别:");
		scanf("%s",stu.sex);
		
		printf("电话:");
		scanf("%s",stu.mobile);
		
		printf("QQ:");
		scanf("%s",stu.QQ);
		
		printf("地址:");
		scanf("%s",stu.address);
	do
	{
			//printf("还要输入其他同学的信息吗?(y/n)");
			//choice=getchar();
			//if(choice!='y'||choice!='Y')
			//{
			//	printf("输入结束！\n");
			//	break;
			//}
			cnt++; 
			Tstu=(STU *)malloc(sizeof(STU));
			if(!Tstu)
			{
				printf("内存分配失败!\n");
				break;
			}
			printf("\n输入第%d个同学的信息:\n",cnt);
			bound('-',20);
			printf("\n姓名:");
			scanf("%s",Tstu->name);//gets(Tstu->name);
			
			printf("学号:");
			scanf("%d",&Tstu->no);
			
			printf("年龄:");
			scanf("%d",&Tstu->age);
			
			printf("性别:");
			scanf("%s",Tstu->sex);
			
			printf("电话:");
			scanf("%s",Tstu->mobile);
			
			printf("QQ:");
			scanf("%s",Tstu->QQ);
			
			printf("地址:");
			scanf("%s",Tstu->address);
			stu.next=Tstu;
			Tstu->next=NULL;
			fflush(stdin);
	}while(1);
	
	printf("输入同学信息为:\n");
	bound('-',20); 
	if(H)
	{
		printf("\n第%d位的同学信息如下:\n",i+1);
		printf("\n姓名:%s\n",H->name);
		printf("学号:%d\n",H->no);
		printf("性别:%s\n",H->sex);
		printf("年龄:%d\n",H->age);
		printf("电话:%s\n",H->mobile);
		printf("  QQ:%s\n",H->QQ);
		printf("地址:%s\n",H->address);
		H=H->next;
	}
	return 0;
} 