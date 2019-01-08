#include  <stdio.h>  /*标准输入/输出函数库*/
#include  <stdlib.h>  /*标准函数库*/
#include  <string.h>  /*字符串函数库*/
void  print_menu_main();
typedef struct student
{
  char   name[10];          /*姓名*/
  char   num[10];           /*学号*/
  char   sex[10];           /*性别*/
  int    chinese;           /*语文成绩*/
  int    math;              /*数学成绩*/
  int    english;           /*英语成绩*/
  int    computer;          /*计算机成绩*/
  struct student  *next;    /*指向下一个学生的指针*/
}stu;
void  input_record()        /*成绩录入子函数*/
{
        int  key_b_in,chinese,math,english,computer;
char name[10],num[10],sex[10],i;
        system("cls"); 
        printf(">请输入学生信息(注最大长度为10个字符):\n");
        printf("姓名:");
scanf("%s",&name[10]);
        printf("学号:");
scanf("%s",&num[10]);
        printf("性别:");
scanf("%s",&sex[10]);
        printf("语文:");
scanf("%d",&chinese);
printf("数学:");
scanf("%d",&math);
printf("英语:");
        scanf("%d",&english);
printf("计算机:");
        scanf("%d",&computer);
printf("是否继续输入学生信息?(Y继续,N返回主菜单)");
        scanf("%d",&key_b_in);
        if(key_b_in==1)  {system("cls"); print_menu_main();}
}
void  show_record()         /*成绩显示子函数*/
{
int  key_b_in;
printf("欢迎键入成绩显示功能");
scanf("%d",&key_b_in);
if(key_b_in==2)  {system("cls"); print_menu_main();}
}
    void  search_record()      /*成绩查询子函数*/
{
int  key_b_in;
printf("请问你要查询那些信息？");
scanf("%d",&key_b_in);
if(key_b_in==3)  {system("cls"); print_menu_main();}
}
    void  update_record()      /*成绩更新子函数*/
{
int  key_b_in;
printf("请问你要更新哪些信息呢？");
scanf("%d",&key_b_in);
if(key_b_in==4)  {system("cls"); print_menu_main();}
}
    void  delete_record()      /*成绩删除子函数*/
{
int  key_b_in;
printf("请问你要删除哪些信息呢？");
scanf("%d",&key_b_in);
if(key_b_in==5)  {system("cls"); print_menu_main();}
}
    void  calculate_record()   /*成绩计算子函数*/
{
int  key_b_in;
printf("请问你要如何计算成绩呢？");
scanf("%d",&key_b_in);
if(key_b_in==6)  {system("cls"); print_menu_main();}
}
   void  save_record()         /*成绩保存子函数*/
   {
   int  key_b_in;
printf("请问你要保存哪些信息呢？");
scanf("%d",&key_b_in);
if(key_b_in==7)  {system("cls"); print_menu_main();}
   }
   void  exit_system()     {  exit(0);}                             /*退出系统子函数*/
void  print_menu_main()
{
int a;
printf("=============================================================================\n");
printf("|学生成绩管理系统\n");
printf("=============================================================================\n");
printf("|\n");
printf("| 1 输入学生信息\n");
printf("| 2 显示学生信息\n");
printf("| 3 查询学生信息\n");
printf("| 4 更新学生信息\n");
printf("| 5 删除学生信息\n");
printf("| 6 计算学生成绩\n");
printf("| 7 保存文件\n");
printf("| 8 退出系统\n");
printf("|\n");
printf("=============================================================================\n");
printf(">请选择：");
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
printf("输入错误，请重新输！（注意：输入有效范围1—8）\n");
}
}
     printf(">请选择：");
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