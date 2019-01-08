#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
	int no;
	char name[10];
	char sex[3];
	char age;
	char mobile[13];
	char QQ[13];
	char address[80];
	struct student *next;
}STU;
char pwd;
STU *stu_first,*stu_end;
char gsave,gfirst;
int *stu;

void addstu(void);
void findstu(void);
void liststu(void);
void modifystu(void);
void summarystu(void);
void delstu(void);
void resetpwd(void);
void readdate(void);
void savedate(void);
char *modi_file(char *file,char *s,int n);
STU *findname(char *name);
STU *findno(int no);
STU *findmobile(char *name);
STU *findQQ(char *name);
void displaystu(STU *stu,char *file,char *name);
void cheakfirst(void);
void bound(char ch,int n);
void login();
void menu();
 
int main(void)
{
	int  *stu_first;
	int  *stu_end;
	*stu_first=*stu_end==NULL;
	int gsave=gfirst=0;
	
	cheakfirst();
	login();
	readdate();
	menu();
	
}
void addstu()
{
	FILE *fp;
	STU *stu;
	int i=0;
	char choice='y';
	STU *stu1;
	
	if((fp=fopen("stu.dat","ab"))==NULL)
	{
		printf("打开文件出错！\n");
		exit(1);
	}
	
	do
	{
		i++;
		stu1=(STU *)malloc(sizeof(STU));//stu1=(STU *)malloc(sizeof(STU));
		
		if(stu1==NULL)
		{
			printf("内存分配失败，按任意键结束！\n");
			exit(1);
		}
		printf("输入第%d个同学的信息:\n",i);
		bound('_',20);
		
		printf("学号:");
		scanf("%d",&stu1->no);
		
		printf("姓名:");
		scanf("%s",stu1->name);
		
		printf("性别:");
		scanf("%s",stu1->sex);
		
		printf("年龄:");
		scanf("%d",&stu1->age);
		
		printf("电话:");
		scanf("%s",stu1->mobile);
		
		printf("QQ:");
		scanf("%s",stu1->QQ);
		
		printf("地址:");
		scanf("%s",stu1->address);
		
		stu1->next=NULL;
		
		if(stu_first==NULL)
		{
			stu_first= stu1;
			stu_end=stu1;
		} 
		else
		{
			stu_end->next=stu1;
			stu_end=stu1;
		}
		fwrite(stu_end,sizeof(STU),1,fp);
		
		gfirst=0;
		printf("\n");
		bound('_',20);
		printf("\n是否继续输入?(y/n)"); 
		fflush(stdin);
		choice=getchar();
		
		if(choice!='y')
		{
			fclose(fp);
			printf("\n输入完毕，按任意键结束！");
			exit(1);
		}
		system("cls");
	}while(1);
}




void bound(char ch,int n)
{
	while(n--)
	{
		putch(ch);
	}	
}


void cheakfirst()
{
	FILE *fp,*fp1;
	char pwd[9],pwd1[9],ch;
	int i;
	if((fp=fopen("config.dat","rb"))==NULL)
	{
		printf("\n新系统，还未进行初始化,单击任意键进行初始化！\n");
		bound("_",50);
		getch();
		
		do
		{
			printf("\n设置登录的系统的密码(八位):");
			for(i=0;i<8&&(pwd[i]=getch())!=13;i++)
			{
				putch("*");
			} 
			printf("\n再次输入登录密码:");
			for(i=0;i<8&&pwd[i]=getch()!=13;i++)
			{
				putch("*");
			}
			pwd[i]='\n';
			pwd1[i]='\n';
			
			if(strcmp(pwd,pwd1)!=0)
			{
				printf("\n两次输入的密码不同，请从新输入！\n\n");
			}
			else
			{
				break;
			}
		}while(1);
		if((fp1=fopen("config.dat","wb"))==NULL)
		{
			printf("\n创建的系统配置文件失败，按任意键结束!\n"); 
			exit(1);
		} 
	 	i=0;
	 	while(pwd[i])
	 	{
 			putw(pwd[i],fp1);
			 i++;	
 		}
		 fclose(fp1); 
		 printf("\n\n系统配置成功，按任意就键推出系统，再从新进入！\n"); 
		 exit(1);
	}
	else
	{
		i=0;
		while(!feof(fp)&&i<8)
		{
			pwd[i++]=getw(fp);
		}
		pwd[i]='\n';
		strcpy(pwd1,pwd);
	}
}




void delstu()
{
	int i,find=0;
	STU *stu1,*stu2;
	char name[10],choice;
	
	system("cls");
	printf("\n输入要删除同学的姓名:\n");
	scanf("%s",name);
	
	stu1=stu_first;
	stu2=stu1;
	while(stu1)
	{
		if(strcmp(stu1->name,name)==0)
		{
			find=1;
			system("cls");
			
			printf("%s同学的信息如下:\n",stu1->name);
			bound('-',25);
			printf("学号：%d\n",stu1->no);
			printf("年龄：%s\n",stu1->age);
			printf("电话：%s\n",stu1->mobile);
			printf("  QQ:%s\n",stu1->QQ);
			printf("地址：%s\n",stu1->address); 
			bound('-',25);
			printf("真的要删除同学的信息吗?(y/n)"); 
			
			fflush(stdin);
			choice=getchar();
			if(choice!='y'&&choice!='Y');
			if(stu1==stu_first)   stu_first=stu1->next;
			else stu2->next=stu1->next;
			
			free(stu1);
			gsave=1;
			savedate();
		}
	}
	if(find)
	{
		bound('-',30);
		printf("未找到姓名为:%s的信息！\n");
	}
}



void displaystu(STU *stu,char *filed,char *name)
{
	if(stu)
	{
		printf("\n%s:%s信息如下:\n",filed,name);
		bound('_',20);
		printf("\n",stu->no);
		printf("\n",stu->name);
		printf("\n",stu->sex);
		printf("\n",stu->age);
		printf("\n",stu->mobile);
		printf("\n",stu->QQ);
		printf("\n",stu->address);
		bound('_',20); 
	}	
	else
	{
		bound('_',20);
		printf("系统中没有%s为：%s 的员工信息!\n",filed,name);
	}
	
}



STU *findname(char *name)
{
	STU *stu1;
	stu1=stu_first;
	
	while(stu1)
	{
		if(strcmp(name,stu1->name)==0)
		{
			return stu1;
			stu1=stu->next;
		}
	}
	return NULL;
}


STU *findno(char no)
{
	STU *stu1;
	stu1=stu_first;
	
	while(stu1)
	{
		if(strcmp(no==stu1->no)
		{
			return stu1;
			stu1=stu->next;
		}
	}
	return NULL;
}


STU *findmobile(char *name)
{
	STU *stu1;
	stu1=stu_first;
	
	while(stu1)
	{
		if(strcmp(name,stu1->mobile)==0)
		{
			return stu1;
			stu1=stu->next;
		}
	}
	return NULL;
}


STU *findQQ(char *name)
{
	STU *stu1;
	stu1=stu_first;
	
	while(stu1)
	{
		if(strcmp(name,stu1->QQ)==0)
		{
			return stu1;
			stu1=stu->next;
		}
	}
	return NULL;
}




void findstu()
{
	int choice,ret=0;num;
	char str[13];
	STU *stu1;
	
	system("cls");
	
	do
	{
		printf("\t查询同学信息:\n");
		printf("请选择菜单:"); 
		bound('_',20);
		printf("\t1.按姓名查询");
		printf("\t2.按学号查询");
		printf("\t3.按电话查询");
		printf("\t4.按QQ查询");
		printf("\t0.返回住菜单"); 
		bound('_',20);
	}
	do
	{
		fflush(stdin);
		choice=getchar();
		system("cls");
		
		switch(choice)
		{
			case '1':
			printf("请输入要查询同学的姓名:");
			scanf("%s",str);
			
			stu1=findname(str);
			displaystu(stu1,"姓名",str);
			break;
			
			case '2':
			printf("请输入要查询同学的学号:") ;
			scanf("%d",&num);
			
			stu1=findno(num);
			itoa(num,str,10);
			displaystu(stu1,"学号",str);
			break;
			
			case '3':
			printf("请输入要查询同学的电话:") ;
			scanf("%s",str);
			
			stu1=findmobile(str);
			displaystu(stu1,"电话",str);
			break;
			
			case '4':
			printf("请输入要查询同学的QQ:") ;
			scanf("%s",str);
			
			stu1=findQQ(str);
			displaystu(stu1,"QQ",str);
			break;
			
			case '0':
			ret=1;
			break;
		}while(choice<'0'||choice>'4');
		system("cls");
		if(ret)  
		{
			break;
		}
	} while(1);
}



void liststu()
{
	STU *stu1;
	
	printf("\n同学列表:\n");
	bound('_',25);
	int *stu1=stu_first;
	
	while(stu)
	{
		printf("学号：d%\n",stu->no);
		printf("姓名：s%\n",stu->name);
		printf("性别：s%\n",stu->sex);
		printf("年龄：d%\n",stu->age);
		printf("电话：s%\n",stu->mobile);
		printf("  QQ：s%\n",stu->QQ);
		printf("地址：s%\n",stu->address);
		bound('_',25);
		stu1=stu->next;
	} 
	printf("\n按任意键返回！\n");
	return 0;
}



void login()
{
	int i,n=3;
	char pwd[9];
	do
	{
		printf("请输入进入系统的密码:");
		for(i=0;i<8&&(=((pwd[i]=getch())!=13);i++)
		{
			putch('*');
		}
		pwd[i]='\0';
		if(strcpy(pwd,pwd))
		{
			printf("\n密码错误，请重新输入:\n");
			system("cls");
			n--;
		}
		else
		{
			break;
		}
	}while(n>0);
	
	if(!n)
	{
		printf("非法登录，请关机！\n");
		exit(1);
	}
}




void menu()
{
	char chioce;
	
	system("cls");
	
	do
	{
		printf("\t学生管理系统\n");
		bound('_',30);
		printf("\n请选择菜单:");
		printf("\t1.输入学生信息:\n");
		printf("\t2.查询学生信息:\n");
		printf("\t3.修改学生信息:\n");
		printf("\t4.删除学生信息:\n");
		printf("\t5.统计学生信息:\n");
		printf("\t6.重设系统密码:\n");
		printf("\t0.推出系统\n");
		bound('_',30);
		
		do
		{
			fflush(stdin);
			chioce=getchar(); 
			system("cls");
			
			swith(choice)
			{
				case '1':  addstu();  break;
				case '2': 
				{
					if(gfirst)
					{
						printf("系统中还没有同学信息，请添加同学信息!");
						break;
					}
					else
					{
						findstu();
						break;
					}
					
				}
				case '3':
				if(gfirst)
				{
					printf("系统中还没有同学信息，请添加同学信息!");
					break;
				}
				else
				{
					liststu();
					break;
				}
				case '4':
				if(gfirst)
				{
					printf("系统中还没有同学信息，请添加同学信息!");
					break;
				}
				else
				{
					modifystu();
					break;
				}
				case '5':
				if(gfirst)
				{
					printf("系统中还没有同学信息，请添加同学信息!");
					break;
				}
				else
				{
					delstu();
					break;
				}
				case '6':
				if(gfirst)
				{
					printf("系统中还没有同学信息，请添加同学信息!");
					break;
				}
				else
				{
					summarystu();
					break;
				}
				case '7': resetpwd();   break;
				case '0': savedate();	exit(0);
				
			}
		}while(choice<'0'||choice>'7');
		system("cls");
	}while(1);	
} 


char *modi_filed(char *filed,char *s,int n)
{
	char *str;
	str=malloc(sizeof(char)*n);
	if(str==NULL)
	{
		printf("内存分配失败，按任意键返回！\n");
		return NULL;
	}
	printf("原%s:%s\n",filed,s);
	printf("修改为(不超过%d个字符):",n);
	scanf("%s",str);
	
	return str;
}



void modifystu()
{
	STU *stu1;
	char name[10];
	int choice;
	char *str;
	
	printf("\n");
	scanf("%s",&name);
	
	stu1=findname(name);
	displaystu(stu1,"姓名",name);
	
	if(stu1)
	{
		printf("\n选择需要修改的项目:\n");
		printf(":"); 
		bound('_',35);
		printf("1.电话");
		printf("2.QQ");
		printf("3.地址");
		printf("0.返回");
		bound('_',35);
	}
	do
	{
		fflush(stdin);
		choice=getchar();
		switch(choice)
		{
			case '1':
			str=modi_filed("电话",stu1->mobile,12);
			if(str!=NULL)
			{
				strcpy(stu1->mobile,str);
				free(str);
			}
			break;
			case '2':
			str=modi_filed("QQ",stu1->QQ,12);
			if(str!=NULL)
			{
				strcpy(stu1->QQ,str);
				free(str);
			}
			break;
			case '3':
			str=modi_filed("地址",stu1->address);
			if(str!=NULL)
			{
				strcpy(stu1->address,str,80);
				free(str);
			}
			break;
			case '0': exit(1);	
		}while(choice<'0'||choice>'8');
		gsave=1;
		savedate();
		printf("\n按任意键返回.\n");
		
	}
	

}



void readdate()
{
	FILE *fp;
	STU *stu1;
	
	if((fp=fopen("stu.dat","rb"))==NULL)
	{
		gfirst=1;
	
	}
	while(!feof(fp))
	{
		stu1=(STU *)malloc(sizeof(STU));
		if(stu==NULL)
		{
			printf("内存分配失败!\n");

		}
		fread(stu,sizeof(STU),1,fp);
		if(feof(fp))
		{
			break;
		}
		if(stu_first==NULL)
		{
			stu_first=stu1;
			stu_end=stu1;
		}
		else
		{
			stu_end->next=stu1;
			stu_end=stu1;
		}
		stu_end->next=NULL;
	} 
	gfirst=0;
	fclose(fp);
}




void resetpwd()
{
	char pwd[9],pwd1[9],ch;
	int i;
	FILE *fp1;
	
	system("cls");
	printf("请输入密码:");
	for(i=0;i<8&&(pwd[i]=getch()!=13);i++)
	{
		putch('*');
	}
	pwd[i]='\0';
	if(strcmp(pwd,pwd)!=0)
	{
		printf("n\输入密码有错误，按任意键返回！\n");
	
	}
	do
	{
		printf("\n输入新密码(最多八位):");
		for(i=0;i<8&&(pwd[i]=getch()!=13);i++)
		{
			putch('*');
		}
		pwd[i]='\0';
		pwd1[i]='\0';
		
		if(strcmp(pwd,pwd)!=0)
		{
			printf("\n两次输入密码不同，请重新输入！\n\n");
		}
		else  break;
	}while(1);
	
	if((fp1+fopen("config.dat","wt"))==NULL)
	{
		printf("\n创建系统配置文件失败，按任意键退出系统！\n");
		exit(1);
	}
	i=0;
	while(pwd[i])
	{
		putw(pwd[i],fp1);
		i++;
	}
	fclose(fp1);
	printf("\n密码成功，按任意键返回!\n");

}



void savedate()
{
	FILE *fp;
	STU *stu1;
	
	if((fp=fopen("stu.dat","wb"))==NULL)
	{
		printf("打开文件出错！\n");
		
	}
	
	stu1=stu_first;
	while(stu1)
	{
		fwrite(stu1,sizeof(STU),1,fp);
		stu1=stu1->next;
	}
	gsave=0;
	fclose(fp);
 
}




void summarystu()
{
	STU *stu1;
	int sum=0,num=0,man=0,woman=0;
	
	stu1=stu_first;
	while(stu1)
	{
		num++;
		if(strcmp(stu1->sex,"男")==0)  man++;
		else woman++; 
	}
	printf("男生：%d",num);
	printf("女生：%d",woman);
	printf("总共：%d",man);
	printf("按任意键返回.\n");
}


