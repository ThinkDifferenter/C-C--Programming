#include  <stdio.h>  /*��׼����/���������*/
#include  <stdlib.h>  /*��׼������*/
#include  <string.h>  /*�ַ���������*/
void  print_menu_main();
typedef struct student
{
  char   name[10];          /*����*/
  char   num[10];           /*ѧ��*/
  char   sex[10];           /*�Ա�*/
  int    chinese;           /*���ĳɼ�*/
  int    math;              /*��ѧ�ɼ�*/
  int    english;           /*Ӣ��ɼ�*/
  int    computer;          /*������ɼ�*/
  struct student  *next;    /*ָ����һ��ѧ����ָ��*/
}stu;
void  input_record()        /*�ɼ�¼���Ӻ���*/
{
        int  key_b_in,chinese,math,english,computer;
char name[10],num[10],sex[10],i;
        system("cls"); 
        printf(">������ѧ����Ϣ(ע��󳤶�Ϊ10���ַ�):\n");
        printf("����:");
scanf("%s",&name[10]);
        printf("ѧ��:");
scanf("%s",&num[10]);
        printf("�Ա�:");
scanf("%s",&sex[10]);
        printf("����:");
scanf("%d",&chinese);
printf("��ѧ:");
scanf("%d",&math);
printf("Ӣ��:");
        scanf("%d",&english);
printf("�����:");
        scanf("%d",&computer);
printf("�Ƿ��������ѧ����Ϣ?(Y����,N�������˵�)");
        scanf("%d",&key_b_in);
        if(key_b_in==1)  {system("cls"); print_menu_main();}
}
void  show_record()         /*�ɼ���ʾ�Ӻ���*/
{
int  key_b_in;
printf("��ӭ����ɼ���ʾ����");
scanf("%d",&key_b_in);
if(key_b_in==2)  {system("cls"); print_menu_main();}
}
    void  search_record()      /*�ɼ���ѯ�Ӻ���*/
{
int  key_b_in;
printf("������Ҫ��ѯ��Щ��Ϣ��");
scanf("%d",&key_b_in);
if(key_b_in==3)  {system("cls"); print_menu_main();}
}
    void  update_record()      /*�ɼ������Ӻ���*/
{
int  key_b_in;
printf("������Ҫ������Щ��Ϣ�أ�");
scanf("%d",&key_b_in);
if(key_b_in==4)  {system("cls"); print_menu_main();}
}
    void  delete_record()      /*�ɼ�ɾ���Ӻ���*/
{
int  key_b_in;
printf("������Ҫɾ����Щ��Ϣ�أ�");
scanf("%d",&key_b_in);
if(key_b_in==5)  {system("cls"); print_menu_main();}
}
    void  calculate_record()   /*�ɼ������Ӻ���*/
{
int  key_b_in;
printf("������Ҫ��μ���ɼ��أ�");
scanf("%d",&key_b_in);
if(key_b_in==6)  {system("cls"); print_menu_main();}
}
   void  save_record()         /*�ɼ������Ӻ���*/
   {
   int  key_b_in;
printf("������Ҫ������Щ��Ϣ�أ�");
scanf("%d",&key_b_in);
if(key_b_in==7)  {system("cls"); print_menu_main();}
   }
   void  exit_system()     {  exit(0);}                             /*�˳�ϵͳ�Ӻ���*/
void  print_menu_main()
{
int a;
printf("=============================================================================\n");
printf("|ѧ���ɼ�����ϵͳ\n");
printf("=============================================================================\n");
printf("|\n");
printf("| 1 ����ѧ����Ϣ\n");
printf("| 2 ��ʾѧ����Ϣ\n");
printf("| 3 ��ѯѧ����Ϣ\n");
printf("| 4 ����ѧ����Ϣ\n");
printf("| 5 ɾ��ѧ����Ϣ\n");
printf("| 6 ����ѧ���ɼ�\n");
printf("| 7 �����ļ�\n");
printf("| 8 �˳�ϵͳ\n");
printf("|\n");
printf("=============================================================================\n");
printf(">��ѡ��");
scanf("%d",&a);
switch(a)
{
case 1:input_record();break;
case 2:show_record();break;
case 3:search_record();break;
case 4:update_record();break;
case 5:delete_record();break;
case 6:calculate_record();break;
case 7:save_record();break;
case 8:exit_system();break;
default:{
printf("��������������䣡��ע�⣺������Ч��Χ1��8��\n");
}
}
     printf(">��ѡ��");
scanf("%d",&a);
switch(a)
{
case 1:input_record();break;
case 2:show_record();break;
case 3:search_record();break;
case 4:update_record();break;
case 5:delete_record();break;
case 6:calculate_record();break;
case 7:save_record();break;
case 8:exit_system();break;
}
}	
void main()
{
  print_menu_main();
}