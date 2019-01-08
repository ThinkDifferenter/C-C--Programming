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
		printf("���ļ�����\n");
		exit(1);
	}
	
	do
	{
		i++;
		stu1=(STU *)malloc(sizeof(STU));//stu1=(STU *)malloc(sizeof(STU));
		
		if(stu1==NULL)
		{
			printf("�ڴ����ʧ�ܣ��������������\n");
			exit(1);
		}
		printf("�����%d��ͬѧ����Ϣ:\n",i);
		bound('_',20);
		
		printf("ѧ��:");
		scanf("%d",&stu1->no);
		
		printf("����:");
		scanf("%s",stu1->name);
		
		printf("�Ա�:");
		scanf("%s",stu1->sex);
		
		printf("����:");
		scanf("%d",&stu1->age);
		
		printf("�绰:");
		scanf("%s",stu1->mobile);
		
		printf("QQ:");
		scanf("%s",stu1->QQ);
		
		printf("��ַ:");
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
		printf("\n�Ƿ��������?(y/n)"); 
		fflush(stdin);
		choice=getchar();
		
		if(choice!='y')
		{
			fclose(fp);
			printf("\n������ϣ��������������");
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
		printf("\n��ϵͳ����δ���г�ʼ��,������������г�ʼ����\n");
		bound("_",50);
		getch();
		
		do
		{
			printf("\n���õ�¼��ϵͳ������(��λ):");
			for(i=0;i<8&&(pwd[i]=getch())!=13;i++)
			{
				putch("*");
			} 
			printf("\n�ٴ������¼����:");
			for(i=0;i<8&&pwd[i]=getch()!=13;i++)
			{
				putch("*");
			}
			pwd[i]='\n';
			pwd1[i]='\n';
			
			if(strcmp(pwd,pwd1)!=0)
			{
				printf("\n������������벻ͬ����������룡\n\n");
			}
			else
			{
				break;
			}
		}while(1);
		if((fp1=fopen("config.dat","wb"))==NULL)
		{
			printf("\n������ϵͳ�����ļ�ʧ�ܣ������������!\n"); 
			exit(1);
		} 
	 	i=0;
	 	while(pwd[i])
	 	{
 			putw(pwd[i],fp1);
			 i++;	
 		}
		 fclose(fp1); 
		 printf("\n\nϵͳ���óɹ���������ͼ��Ƴ�ϵͳ���ٴ��½��룡\n"); 
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
	printf("\n����Ҫɾ��ͬѧ������:\n");
	scanf("%s",name);
	
	stu1=stu_first;
	stu2=stu1;
	while(stu1)
	{
		if(strcmp(stu1->name,name)==0)
		{
			find=1;
			system("cls");
			
			printf("%sͬѧ����Ϣ����:\n",stu1->name);
			bound('-',25);
			printf("ѧ�ţ�%d\n",stu1->no);
			printf("���䣺%s\n",stu1->age);
			printf("�绰��%s\n",stu1->mobile);
			printf("  QQ:%s\n",stu1->QQ);
			printf("��ַ��%s\n",stu1->address); 
			bound('-',25);
			printf("���Ҫɾ��ͬѧ����Ϣ��?(y/n)"); 
			
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
		printf("δ�ҵ�����Ϊ:%s����Ϣ��\n");
	}
}



void displaystu(STU *stu,char *filed,char *name)
{
	if(stu)
	{
		printf("\n%s:%s��Ϣ����:\n",filed,name);
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
		printf("ϵͳ��û��%sΪ��%s ��Ա����Ϣ!\n",filed,name);
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
		printf("\t��ѯͬѧ��Ϣ:\n");
		printf("��ѡ��˵�:"); 
		bound('_',20);
		printf("\t1.��������ѯ");
		printf("\t2.��ѧ�Ų�ѯ");
		printf("\t3.���绰��ѯ");
		printf("\t4.��QQ��ѯ");
		printf("\t0.����ס�˵�"); 
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
			printf("������Ҫ��ѯͬѧ������:");
			scanf("%s",str);
			
			stu1=findname(str);
			displaystu(stu1,"����",str);
			break;
			
			case '2':
			printf("������Ҫ��ѯͬѧ��ѧ��:") ;
			scanf("%d",&num);
			
			stu1=findno(num);
			itoa(num,str,10);
			displaystu(stu1,"ѧ��",str);
			break;
			
			case '3':
			printf("������Ҫ��ѯͬѧ�ĵ绰:") ;
			scanf("%s",str);
			
			stu1=findmobile(str);
			displaystu(stu1,"�绰",str);
			break;
			
			case '4':
			printf("������Ҫ��ѯͬѧ��QQ:") ;
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
	
	printf("\nͬѧ�б�:\n");
	bound('_',25);
	int *stu1=stu_first;
	
	while(stu)
	{
		printf("ѧ�ţ�d%\n",stu->no);
		printf("������s%\n",stu->name);
		printf("�Ա�s%\n",stu->sex);
		printf("���䣺d%\n",stu->age);
		printf("�绰��s%\n",stu->mobile);
		printf("  QQ��s%\n",stu->QQ);
		printf("��ַ��s%\n",stu->address);
		bound('_',25);
		stu1=stu->next;
	} 
	printf("\n����������أ�\n");
	return 0;
}



void login()
{
	int i,n=3;
	char pwd[9];
	do
	{
		printf("���������ϵͳ������:");
		for(i=0;i<8&&(=((pwd[i]=getch())!=13);i++)
		{
			putch('*');
		}
		pwd[i]='\0';
		if(strcpy(pwd,pwd))
		{
			printf("\n�����������������:\n");
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
		printf("�Ƿ���¼����ػ���\n");
		exit(1);
	}
}




void menu()
{
	char chioce;
	
	system("cls");
	
	do
	{
		printf("\tѧ������ϵͳ\n");
		bound('_',30);
		printf("\n��ѡ��˵�:");
		printf("\t1.����ѧ����Ϣ:\n");
		printf("\t2.��ѯѧ����Ϣ:\n");
		printf("\t3.�޸�ѧ����Ϣ:\n");
		printf("\t4.ɾ��ѧ����Ϣ:\n");
		printf("\t5.ͳ��ѧ����Ϣ:\n");
		printf("\t6.����ϵͳ����:\n");
		printf("\t0.�Ƴ�ϵͳ\n");
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
						printf("ϵͳ�л�û��ͬѧ��Ϣ�������ͬѧ��Ϣ!");
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
					printf("ϵͳ�л�û��ͬѧ��Ϣ�������ͬѧ��Ϣ!");
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
					printf("ϵͳ�л�û��ͬѧ��Ϣ�������ͬѧ��Ϣ!");
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
					printf("ϵͳ�л�û��ͬѧ��Ϣ�������ͬѧ��Ϣ!");
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
					printf("ϵͳ�л�û��ͬѧ��Ϣ�������ͬѧ��Ϣ!");
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
		printf("�ڴ����ʧ�ܣ�����������أ�\n");
		return NULL;
	}
	printf("ԭ%s:%s\n",filed,s);
	printf("�޸�Ϊ(������%d���ַ�):",n);
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
	displaystu(stu1,"����",name);
	
	if(stu1)
	{
		printf("\nѡ����Ҫ�޸ĵ���Ŀ:\n");
		printf(":"); 
		bound('_',35);
		printf("1.�绰");
		printf("2.QQ");
		printf("3.��ַ");
		printf("0.����");
		bound('_',35);
	}
	do
	{
		fflush(stdin);
		choice=getchar();
		switch(choice)
		{
			case '1':
			str=modi_filed("�绰",stu1->mobile,12);
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
			str=modi_filed("��ַ",stu1->address);
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
		printf("\n�����������.\n");
		
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
			printf("�ڴ����ʧ��!\n");

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
	printf("����������:");
	for(i=0;i<8&&(pwd[i]=getch()!=13);i++)
	{
		putch('*');
	}
	pwd[i]='\0';
	if(strcmp(pwd,pwd)!=0)
	{
		printf("n\���������д��󣬰���������أ�\n");
	
	}
	do
	{
		printf("\n����������(����λ):");
		for(i=0;i<8&&(pwd[i]=getch()!=13);i++)
		{
			putch('*');
		}
		pwd[i]='\0';
		pwd1[i]='\0';
		
		if(strcmp(pwd,pwd)!=0)
		{
			printf("\n�����������벻ͬ�����������룡\n\n");
		}
		else  break;
	}while(1);
	
	if((fp1+fopen("config.dat","wt"))==NULL)
	{
		printf("\n����ϵͳ�����ļ�ʧ�ܣ���������˳�ϵͳ��\n");
		exit(1);
	}
	i=0;
	while(pwd[i])
	{
		putw(pwd[i],fp1);
		i++;
	}
	fclose(fp1);
	printf("\n����ɹ��������������!\n");

}



void savedate()
{
	FILE *fp;
	STU *stu1;
	
	if((fp=fopen("stu.dat","wb"))==NULL)
	{
		printf("���ļ�����\n");
		
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
		if(strcmp(stu1->sex,"��")==0)  man++;
		else woman++; 
	}
	printf("������%d",num);
	printf("Ů����%d",woman);
	printf("�ܹ���%d",man);
	printf("�����������.\n");
}


