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

int main()
{
		STU *stu1;
		printf("����ͬѧ����Ϣ:\n");
		printf("����:");
		scanf("%s",stu1->name);
		
		printf("ѧ��:");
		scanf("%d",&stu1->no);
		
		printf("����:");
		scanf("%d",&stu1->age);
		
		printf("�Ա�:");
		scanf("%s",stu1->sex);
		
		printf("�绰:");
		scanf("%s",stu1->mobile);
		
		printf("QQ:");
		scanf("%s",stu1->QQ);
		
		printf("��ַ:");
		scanf("%s",stu1->address);
		
		printf("\n��ͬѧ����ϢΪ:\n");
		printf("����:%s\n",stu1->name);
		printf("ѧ��:%d\n",stu1->no);
		printf("�Ա�:%s\n",stu1->sex);
		printf("����:%d\n",stu1->age);
		printf("�绰:%s\n",stu1->mobile);
		printf("  QQ:%s\n",stu1->QQ);
		printf("��ַ:%s\n",stu1->address);
		return 0;
}