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
{		STU *stu;
		STU stu1;
		stu=&stu1;
		printf("�����һ����ͬѧ��Ϣ:");
		printf("\n����:");
		scanf("%s",stu1.name);
		
		printf("ѧ��:");
		scanf("%d",&stu1.no);
		
		printf("����:");
		scanf("%d",&stu1.age);
		
		printf("�Ա�:");
		scanf("%s",stu1.sex);
		
		printf("�绰:");
		scanf("%s",stu1.mobile);
		
		printf("QQ:");
		scanf("%s",stu1.QQ);
		
		printf("��ַ:");
		scanf("%s",stu1.address);
		
		printf("\n��ͬѧ����ϢΪ:\n");
		printf("����:%s\n",stu->name);
		printf("ѧ��:%d\n",stu->no);
		printf("�Ա�:%s\n",stu->sex);
		printf("����:%d\n",stu->age);
		printf("�绰:%s\n",stu->mobile);
		printf("  QQ:%s\n",stu->QQ);
		printf("��ַ:%s\n",stu->address);
	 	return 0;
}