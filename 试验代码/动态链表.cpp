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
	printf("�����1��ͬѧ��Ϣ:\n");
	bound('-',20);
		printf("\n����:");
		scanf("%s",stu.name);//gets(stu.name);
		
		printf("ѧ��:");
		scanf("%d",&stu.no);
		
		printf("����:");
		scanf("%d",&stu.age);
		
		printf("�Ա�:");
		scanf("%s",stu.sex);
		
		printf("�绰:");
		scanf("%s",stu.mobile);
		
		printf("QQ:");
		scanf("%s",stu.QQ);
		
		printf("��ַ:");
		scanf("%s",stu.address);
	do
	{
			//printf("��Ҫ��������ͬѧ����Ϣ��?(y/n)");
			//choice=getchar();
			//if(choice!='y'||choice!='Y')
			//{
			//	printf("���������\n");
			//	break;
			//}
			cnt++; 
			Tstu=(STU *)malloc(sizeof(STU));
			if(!Tstu)
			{
				printf("�ڴ����ʧ��!\n");
				break;
			}
			printf("\n�����%d��ͬѧ����Ϣ:\n",cnt);
			bound('-',20);
			printf("\n����:");
			scanf("%s",Tstu->name);//gets(Tstu->name);
			
			printf("ѧ��:");
			scanf("%d",&Tstu->no);
			
			printf("����:");
			scanf("%d",&Tstu->age);
			
			printf("�Ա�:");
			scanf("%s",Tstu->sex);
			
			printf("�绰:");
			scanf("%s",Tstu->mobile);
			
			printf("QQ:");
			scanf("%s",Tstu->QQ);
			
			printf("��ַ:");
			scanf("%s",Tstu->address);
			stu.next=Tstu;
			Tstu->next=NULL;
			fflush(stdin);
	}while(1);
	
	printf("����ͬѧ��ϢΪ:\n");
	bound('-',20); 
	if(H)
	{
		printf("\n��%dλ��ͬѧ��Ϣ����:\n",i+1);
		printf("\n����:%s\n",H->name);
		printf("ѧ��:%d\n",H->no);
		printf("�Ա�:%s\n",H->sex);
		printf("����:%d\n",H->age);
		printf("�绰:%s\n",H->mobile);
		printf("  QQ:%s\n",H->QQ);
		printf("��ַ:%s\n",H->address);
		H=H->next;
	}
	return 0;
} 