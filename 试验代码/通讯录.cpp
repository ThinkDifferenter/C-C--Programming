#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h> 
    struct person
         {
	       char name[15];
	       char sex[2];
           int nianling;
           long int youbian;
	       char addr[50];
	       char celephone[22];
	       char homephone[22];
       	   char company[20];
	       char email[40];
	       long int QQ;
        }per[500];
   int num=0;//*外部变量num为文件中的纪录数*//
   FILE *fp; 
   void mainmenu();//*主菜单*//
   void newrecord();//新添纪录*//
   
   void xiugaimenu();//*修改菜单*//
   void xiugaibyname();//*按姓名修改*//
   void xiugaibycelephone();//*按手机号码修改*//
   void xiugaixiangmu(int a);//*修改项目*//
   
   void searchmenu();//*查询菜单*// 
   void searchbyname();//*按姓名查询*//
   void searchbycelephone();//*按手机号码查询*//
   void searchbyhomephone();//*按家庭电话号码查询*//
   void searchbyqq();//*按QQ查询*//
   
   void deletemenu();//*删除菜单*//
   void deleteall();//*删除所有信 息*// 
   void deleteone();//*删除单个*//
   
   void showall();//*输 出 全 部 信 息*// 
   
   void readfromfile();//*读取文件*// 
   void writetofile();//*写入文件*// /
   
   void deletebycelephone();  //*按手机号码删除*//
   void deletebyname();//*按姓名删除*/ 
   
   void listbycelephone();//*按手机号码排序*// 
   void listbyname();//*按姓名排序*// 
   void listmenu();//*排序菜单*// 
   


int main()//*主函数*// 
{ 
	system("cls");
	readfromfile(); 
	while (1) 
	{ 
		mainmenu(); 
	} 
	return 0;
} //*主函数结束*//





void mainmenu()//*主菜单函数*// 
{ 
	int a; 
	system("cls"); 
	system("color 2a");//shell 颜色代码控制 
	printf("\n\t  您 好! 欢 迎 使 用 通 讯 录!\n");
	printf("             1: 添 加 个 人 信 息\n");
	printf("             2: 查 询 个 人 信 息\n");
	printf("             3: 删 除 个 人 信 息\n");
	printf("             4: 修 改 个 人 信 息\n");
	printf("             5: 信 息 排 序\n");
	printf("             6: 输 出 全 部 信 息\n");
	printf("             7: 写 入 文 件\n");
	printf("             8: 读 取 文 件\n");
	printf("             9: 删除所有\n");
	printf("             0: 退 出  \n");
	printf("          请输入您的数字选择:    ");
	loop1: scanf("%d",&a); 
	switch (a) 
	{

		case 1:newrecord();break; 
		case 2:searchmenu();break; 
		case 3:deletemenu();break; 
		case 4:xiugaimenu();break;
		case 5:listmenu();break;
		case 6:showall();break;
		case 7:writetofile();break; 
		case 8:readfromfile();break;
		case 9:deleteall();break;
		case 0:exit(0); 
		default:printf("对不起！您的输入有误！请重新输入:   ");goto loop1; 
	} 
} 


void newrecord()//*添加纪录*// 
{
     int a; 
     system("cls"); 
     system("color 2a"); 
loop:	  printf("\n\n\n\n\t\t  请输入您要添加的联系人的信息： \n"); 	
  	  printf("\n请输入姓名:\n");
name: scanf("%s",&per[num].name);
	  if(strlen(per[num].name)>15)
	   {
		  printf("对不起！您的输入有误！请重新输入");
		  goto name;
	   }
      printf("\n请输入性别:\n");
sex:  scanf("%s",&per[num].sex);
	  if(strlen(per[num].sex)==0)
	  {
	     printf("对不起！您的输入有误！请重新输入");
	     goto sex;
	  }
	  printf("\n请输入年龄:");
nianling:  	scanf("%d",&per[num].nianling); 
      if(per[num].nianling<10||per[num].nianling>110)
       {
       	  printf("对不起！您的输入有误！请重新输入");
       	  goto  nianling;
       }
      printf("\n请输入邮编\n");
youbian:    scanf("%d",&per[num].youbian); 
      if(per[num].youbian<10000||per[num].youbian>999999) 
	  {
	      printf("对不起！您的输入有误！请重新输入");
		  goto  youbian;
	  }
	  printf("\n请输入地址\n");
addr:	scanf("%s",&per[num].addr);
	  if(strlen(per[num].addr)>50||strlen(per[num].addr)<4)
	  {
		  printf("对不起！您的输入有误！请重新输入\n");
		  goto addr;
	  }
	  printf("\n请输入手机号码:\n"); 
celephone:   scanf("%s",&per[num].celephone);
	  if(strlen(per[num].celephone)!=11) 
	  {
		  printf("对不起！您的输入有误！请重新输入\n");
		  goto celephone;
	  }	  
	  printf("\n请输入家庭电话号码:\n");
homephone:	scanf("%s",&per[num].homephone);
	  if(strlen(per[num].homephone)!=11)
	     {
		    printf("对不起！您的输入有误！请重新输入\n");
		    goto homephone;
	     }
	  printf("\n请输入公司名称:");
company:    scanf("%s",&per[num].company);
	if(strlen(per[num].company)>20||strlen(per[num].company)<10)
	  {
		  printf("对不起！您的输入有误！请重新输入");
		  goto company;
	  }
	  printf("\n输入电子邮箱:"); 
email:	scanf("%s",&per[num].email); 
	if(strlen(per[num].email)>30||strlen(per[num].email)<4)
	  {
		  printf("对不起！您的输入有误！请重新输入");
		  goto email;
	  }
	printf("\n输入QQ号码:");
QQ:	scanf("%ld",&per[num].QQ);
	if(per[num].QQ>1600000000||per[num].QQ<10000000)
	  {
		  printf("对不起！您的输入有误！请重新输入");
		  goto QQ;
	  }
	num++; 
	printf("\n是否继续添加?\n"); 
	printf("\n请按1和2（1代表继续；2代表不继续）\n");
    printf("请输入您的选择  ");
    scanf("%d",&a);
    if(a==1)
    {
	  goto loop;
    }
    else
    {
	   return;
    }
} 




void searchmenu()//*查询菜单*// 
{ 
	int a; 
	system("cls");
	system("color 2a"); 
	printf("\n\t\t  欢   迎   使    用    查    询    菜   单"); 
	printf("\n\t\t           1-按手机号码查询");
	printf("\n\t\t           2-按姓名查询");
	printf("\n\t\t           3-按家庭电话号码查询"); 
	printf("\n\t\t           4-按QQ查询"); 
    printf("\n\t\t           5-返回主菜单"); 
	printf("\n\t\t"); 
    printf("请输入您的选择  ");
	scanf("%d",&a); 
	switch (a) 
	{  
		case 1:searchbycelephone();break; 
		case 2:searchbyname();break; 
		case 3:searchbyhomephone();break;
		case 4:searchbyqq();break;	
		case 5:mainmenu();break; 
	} 
} 


void searchbycelephone()//*按手机号码查询*// 
{ 
	int mark=0; 
	int i,j; 
	int a=0; 
	char celephone[11]; 
	printf("\n               按手机号码查找                \n"); 
	printf("\n请输入手机号码:\n"); 
	scanf("%s",celephone); 
	for(i=0;i<num;i++) 
	{ 
		if (strcmp(per[i].celephone,celephone)==0) 
		{ 
			printf("\n                 以下是您查找的联系人的信息        "); 
			printf("\n________________________________"); 
			printf("\n名字： %s",per[i].name); 
			printf("\n性别： %s",per[i].sex); 
			printf("\n年龄： %d",per[i].nianling); 
			printf("\n邮编 ： %ld",per[i].youbian);
			printf("\n地址： %s",per[i].addr);
			printf("\n手机号码： %s",per[i].celephone);
			printf("\n家庭电话号码：%s",per[i].homephone); 
			printf("\n公司名称：%s",per[i].company);
			printf("\n电子邮件：%s",per[i].email);
			printf("\nQQ号码：%ld",per[i].QQ);
			printf("\n________________________________"); 
		    printf("\n请按任意数字键返回主菜单"); 
		    mark++;
		    scanf("%d",&j); 
		    return; 
		} 
	} 
	if (mark==0) 
	{ 
		printf("\n对不起!没有该联系人的信息!"); 
		printf("\n请按任意数字键返回主菜单"); 
		scanf("%d",&j); 
		return; 
	} 
}



void searchbyname()//*按姓名查询*// 
{ 
	int mark=0; 
	int i,j,findmark=0; 
	int a=0;
	char name[15]; 
	printf("\n                  按姓名查找                  "); 
	printf("\n请输入姓名:"); 
	scanf("%s",name); 
	for(i=a;i<num;i++) 
	{ 
		if (strcmp(per[i].name,name)==0) 
		{ 
            findmark++;
			printf("\n\t\t               以下是您查找的联系人的信息            "); 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t名字： %s",per[i].name); 
			printf("\n\t\t性别： %s",per[i].sex); 
			printf("\n\t\t年龄： %d",per[i].nianling); 
			printf("\n\t\t邮编 ： %ld",per[i].youbian);
			printf("\n\t\t地址： %s",per[i].addr);
			printf("\n\t\t手机号码： %s",per[i].celephone);
			printf("\n\t\t家庭电话号码：%s",per[i].homephone); 
			printf("\n\t\t公司名称：%s",per[i].company);
			printf("\n\t\t电子邮件：%s",per[i].email);
			printf("\n\t\tQQ号码：%ld",per[i].QQ);
			printf("\n\t\t________________________________"); 
			if ((i+1)<num) 
			{ 
				printf("\n是否继续查找相同名字的联系人的信息?（1代表继续；2代表不继续）"); 
				scanf("%d",&j);
				if (j==1) 
				{ 
					a=i; 
                    mark++;
					continue; 
				} 
				else 
					break; 
			} 
			else
			{
                 printf("\n请按任意数字键返回主菜单"); 
		         scanf("%d",&j); 
		         return; 
			}
		} 
	} 
	if(mark!=0) 
	{ 
		printf("\n对不起! 没有相同名字的该联系人的信息!！"); 
		printf("\n请按任意数字键返回主菜单"); 
		scanf("%d",&j); 
		return; 
	} 
	else if(findmark==0) 
	{ 
		printf("\n对不起!没有该联系人的信息!"); 
		printf("\n请按任意数字键返回主菜单"); 
		scanf("%d",&j); 
		return;  
	} 
} 



void searchbyhomephone()//*按家庭电话号码查询*// 
{ 
	int mark=0; 
	int i,j; 
	int a=0;
	char homephone[11]; 
	printf("\n\t\t                   按家庭电话号码查找                     "); 
	printf("\n请输入家庭电话号码:"); 
	scanf("%s",homephone); 
	for(i=0;i<num;i++) 
	{ 
		if (strcmp(per[i].homephone,homephone)==0) 
		{ 
			printf("\n\t\t                以下是您要查找的联系人的信息          "); 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t名字： %s",per[i].name); 
			printf("\n\t\t性别： %s",per[i].sex); 
			printf("\n\t\t年龄： %d",per[i].nianling); 
			printf("\n\t\t邮编 ： %ld",per[i].youbian);
			printf("\n\t\t地址： %s",per[i].addr);
			printf("\n\t\t手机号码： %s",per[i].celephone);
			printf("\n\t\t家庭电话号码：%s",per[i].homephone); 
			printf("\n\t\t公司名称：%s",per[i].company);
			printf("\n\t\t电子邮件：%s",per[i].email);
			printf("\n\t\tQQ号码：%ld",per[i].QQ);
			printf("\n\t\t________________________________"); 
            printf("\n\t\t请按任意数字键返回主菜单");
			mark++; 
		    scanf("%d",&j); 
		    return; 
		} 
	} 
	if (mark==0) 
	{ 
		printf("\n\t\t对不起!没有该联系人的信息!"); 
		printf("\n\t\t请按任意数字键返回主菜单"); 
		scanf("%d",&j); 
		return;  
	} 
} 



void searchbyqq()//*按QQ查询*// 
{ 
	int mark=0; 
	int i,j; 
	long int QQ; 
	printf("\n\t\t                     按QQ号码查找                      \n"); 
	printf("\n请输入QQ号码:"); 
	scanf("%ld",&QQ); 
	for(i=0;i<num;i++) 
	{ 
		if(per[i].QQ==QQ) 
		{ 
			printf("\n\t\t                 以下是您查找的联系人的信息           "); 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t名字： %s",per[i].name); 
			printf("\n\t\t性别： %s",per[i].sex); 
			printf("\n\t\t年龄： %d",per[i].nianling); 
			printf("\n\t\t邮编 ： %ld",per[i].youbian);
			printf("\n\t\t地址： %s",per[i].addr);
			printf("\n\t\t手机号码： %s",per[i].celephone);
			printf("\n\t\t家庭电话号码：%s",per[i].homephone); 
			printf("\n\t\t公司名称：%s",per[i].company);
			printf("\n\t\t电子邮件：%s",per[i].email);
			printf("\n\t\tQQ号码：%ld",per[i].QQ);
			printf("\n\t\t________________________________"); 
		    printf("\n\t\t请按任意数字键返回主菜单"); 
		    mark++;
		    scanf("%d",&j); 
		    return; 
		} 
	} 
	if (mark==0) 
	{ 
		printf("\n\t\t对不起!没有该联系人的信息!"); 
		printf("\n\t\t请按任意数字键返回主菜单"); 
		scanf("%d",&j); 
		return; 
	} 
} 



 
void deletemenu()//*删除菜单*// 
{  
    int i,j;
    system("cls");
	system("color 3b");   
	if(num==0) 
	{ 
		printf("\n\t\t对不起!文件中无任何纪录!");
		printf("\n\t\t请先添加个人信息!");
		printf("\n\t\t请按任意数字键返回主菜单"); 
		scanf("%d",&j); 
		return; 
	} 
	else
	{
	   printf("\n\t\t                   删 除 菜 单                   "); 
       printf("\n\t\t                   1-删除单个                    ");	
	   printf("\n\t\t                  2-返回主菜单                   "); 
	   printf("\n\t\t                                                 "); 
	   printf("\n\t\t请输入您的数字选择:    "); 
	   loop4: scanf("%d",&i); 
	   switch (i) 
	   { 
		case 1:deleteone();break; 
		case 2:mainmenu();break; 
		default:printf("对不起！您的输入有误！请重新输入:   ");goto loop4; 
	   }
	}
} 



void deleteone()//*删除单个*//
{ 
	int i; 
	printf("\n\t\t1-按手机号码删除 2-按姓名删除"); 
	printf("\n\t\t请输入您的选择："); 
	loop5:scanf("%d",&i);; 
	switch (i) 
	{ 
	case 1:deletebycelephone();break; 
	case 2:deletebyname();break;
    default:printf("对不起！您的输入有误！请重新输入:   ");goto loop5; 
	} 
}


void deletebyname()//姓名删除*// 
{ 
	int a=0; 
	int findmark=0; 
	int i,j,k; 
	int deletemark=0; 
	char name[15]; 
	printf("\n\t\t请输入您要删除的联系人的姓名："); 
	scanf("%s",name); 
	for (i=a;i<num;i++) 
	{ 
		if (strcmp(per[i].name,name)==0) 
		{ 
			printf("\n\t\t以下是您要删除的联系人的纪录："); 
			findmark++; 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t名字： %s",per[i].name); 
			printf("\n\t\t性别： %s",per[i].sex); 
			printf("\n\t\t年龄： %d",per[i].nianling); 
			printf("\n\t\t邮编 ： %ld",per[i].youbian);
			printf("\n\t\t地址： %s",per[i].addr);
			printf("\n\t\t手机号码： %s",per[i].celephone);
			printf("\n\t\t家庭电话号码：%s",per[i].homephone); 
			printf("\n\t\t公司名称：%s",per[i].company);
			printf("\n\t\t电子邮件：%s",per[i].email);
			printf("\n\t\tQQ号码：%ld",per[i].QQ);
			printf("\n\t\t________________________________"); 
			printf("\n\t\t是否删除?（1代表删除；2代表不删除）\n");
			printf("\n\t\t请输入您的数字选择:    "); 
			scanf("%d",&k); 
			if(k==1) 
			{ 
				for (j=i;j<num-1;j++) //*纪录移动，从per数组中删除之*// 
				per[j]=per[j+1]; 
				num--; 
				deletemark++; 
				printf("\n\t\t删除成功"); 
				if((i+1)<num) 
				{ 
					printf("\n\t\t是否继续删除相同姓名的联系人的信息?（1代表删除；2代表不删除）"); 
			        printf("\n\t\t请输入您的数字选择:    "); 
			        scanf("%d",&k); 
			        if(k=1)
					{ 
						a=i; 
						findmark++;
						continue; 
					} 
				} 
				printf("\n\t\t是否继续删除?（1代表继续；2代表不继续）"); 
                printf("\n\t\t请输入您的数字选择:    "); 
                scanf("%d",&k);
                if(k==1)
				   deleteone(); 
				else
				break; 
			} 
		}	
		else 
		continue; 
	} 
	if((deletemark==0)&&(findmark==0)) 
	{ 
		printf("\n\t\t对不起!没有该联系人的纪录!"); 
		printf("\n\t\t是否继续删除?（1代表继续；2代表不继续）"); 
		printf("          请输入您的数字选择:    ");
		scanf("%d",&k);
		if(k==1)  
		  deleteone(); 

	} 
	else if(findmark!=0) 
	{ 
		printf("\n\t\t对不起!没有重名信息!"); 
		printf("\n\t\t是否继续删除?（1代表继续；2代表不继续）"); 
		printf("          请输入您的数字选择:    ");
		scanf("%d",&k);
	    if(k==1) 
		   deleteone(); 
	} 
} 


void deletebycelephone()//*按手机号码删除*// 
{ 
	int i,j,h,m; 
	int deletemark=0; 
	char celephone[11]; 
	printf("\n\t\t请输入要删除的联系人的手机号码："); 
	scanf("%s",celephone); 
	for(i=0;i<num;i++) 
	{ 
		if(strcmp(per[i].celephone,celephone)==0) 
		{ 
		    deletemark++;
			printf("\n\t\t以下是您要删除的联系人的纪录：");
			printf("\n\t\t________________________________"); 		 
			printf("\n\t\t名字： %s",per[i].name); 
			printf("\n\t\t性别： %s",per[i].sex); 
			printf("\n\t\t年龄： %d",per[i].nianling); 
			printf("\n\t\t邮编 ： %ld",per[i].youbian);
			printf("\n\t\t地址： %s",per[i].addr);
			printf("\n\t\t手机号码： %s",per[i].celephone);
			printf("\n\t\t家庭电话号码：%s",per[i].homephone); 
			printf("\n\t\t公司名称：%s",per[i].company);
			printf("\n\t\t电子邮件：%s",per[i].email);
			printf("\n\t\tQQ号码：%ld",per[i].QQ);
			printf("\n\t\t________________________________"); 
			printf("\n\t\t是否删除?（1代表删除；2代表不删除）\n"); 
			printf("          请输入您的数字选择:    ");
			scanf("%d",&h);
	        if(h==1) 
			{ 
				for (j=i;j<num-1;j++) /*纪录移动，从per数组中删除之*/ 
				per[j]=per[j+1]; 
				num--;  
				printf("\n\t\t删除成功"); 
				printf("\n是否继续删除?（1代表继续；2代表不继续）\n"); 
				printf("          请输入您的数字选择:    ");
				scanf("%d",&h);
	            if(h==1)  
				     deletebycelephone(); 
			} 
		} 
	} 
	if(deletemark==0) 
	{ 
		printf("\n\t\t对不起!没有该联系人的纪录!"); 
		printf("\n\t\t是否继续删除?（1代表继续；2代表不继续）\n"); 
		printf("          请输入您的数字选择:    ");
		scanf("%d",&m);
	    if(m==1)  
		   deletebycelephone();
	}
} 



void xiugaimenu()//*修改菜单*//
{
	int i,j;
    system("cls");
	system("color 3f");
	if(num==0) 
	{ 
		printf("\n\t\t对不起!文件中无任何纪录!"); 
		printf("\n\t\t请按任意数字键返回主菜单"); 
		scanf("%d",&j); 
		return;  
	}
	else
	{ 
	    printf("\n\t\t 1-按姓名修改   2-按手机号码修改\n"); 
	    printf("          请输入您的数字选择:    ");
	loop6:scanf("%d",&i);
	    switch (i) 
	    { 
	      case 1:xiugaibyname();break; 
	      case 2:xiugaibycelephone();break; 
	      default:printf("对不起！您的输入有误！请重新输入:   ");goto loop6;
	    } 
	}
}



void xiugaibyname()//*按姓名修改*//
{
	int a=0; 
	int findmark=0; 
	int xiugaimark=0; 
	int i,j; 
	char name[15]; 
	printf("\n\t\t请输入要修改联系人的姓名："); 
	scanf("%s",name); 
	for (i=a;i<num;i++) 
	{ 
		if (strcmp(per[i].name,name)==0) 
		{ 
			printf("\n\t\t以下是您要修改的联系人的纪录："); 
			findmark++; 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t名字： %s",per[i].name); 
			printf("\n\t\t性别： %s",per[i].sex); 
			printf("\n\t\t年龄： %d",per[i].nianling); 
			printf("\n\t\t邮编 ： %ld",per[i].youbian);
			printf("\n\t\t地址： %s",per[i].addr);
			printf("\n\t\t手机号码： %s",per[i].celephone);
			printf("\n\t\t家庭电话号码：%s",per[i].homephone); 
			printf("\n\t\t公司名称：%s",per[i].company);
			printf("\n\t\t电子邮件：%s",per[i].email);
			printf("\n\t\tQQ号码：%ld",per[i].QQ);
			printf("\n\t\t________________________________");
			printf("\n\t\t是否修改?（1代表修改；2代表不修改）"); 
			printf("          请输入您的数字选择:    ");
			scanf("%d",&j);
			if (j==1) 
			{ 
				xiugaixiangmu(i);
				xiugaimark++; 
				printf("\n\t\t修改成功"); 
				if((i+1)<num) 
				{ 
					printf("\n\t\t是否继续修改相同姓名的联系人的信息?（1代表继续；2代表不继续）"); 
					printf("          请输入您的数字选择:    ");
					scanf("%d",&j);
					if (j==1) 
					{ 
						a=i;
						findmark++; 
						continue; 
					} 
				} 
				printf("\n\t\t是否继续修改?（1代表继续；2代表不继续）"); 
				printf("          请输入您的数字选择:    ");
				scanf("%d",&j);
				if (j==1) 
				xiugaibyname(); 
				return; 
			} 
		}
	}
	if ((xiugaimark==0)&&(findmark==0)) 
	{ 
		printf("\n\t\t没有该联系人的纪录"); 
		printf("\n\t\t是否继续修改?（1代表继续；2代表不继续）"); 
		printf("          请输入您的数字选择:    ");
		scanf("%d",&j);
		if (j==1) 
		    xiugaibyname(); 
		return; 
	}
	else if (findmark!=0) 
	{ 
		printf("\n\t\t没有重名信息"); 
		printf("\n\t\t是否继续修改?（1代表继续；2代表不继续）"); 
		printf("          请输入您的数字选择:    ");
		scanf("%d",&j);
		if (j==1) 
		xiugaibyname(); 
		return; 
	} 
}



void xiugaibycelephone()//*按手机号码修改*//
{
	int findmark=0; 
	int i,j; 
	char celephone[11]; 
	printf("\n\t\t请输入要修改联系人的手机号码："); 
	scanf("%s",celephone); 
	for (i=0;i<num;i++) 
	{ 
		if (strcmp(per[i].celephone,celephone)==0) 
		{ 
			printf("\n\t\t以下是您要修改的联系人的纪录："); 
			findmark++; 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t名字： %s",per[i].name); 
			printf("\n\t\t性别： %s",per[i].sex); 
			printf("\n\t\t年龄： %d",per[i].nianling); 
			printf("\n\t\t邮编 ： %ld",per[i].youbian);
			printf("\n\t\t地址： %s",per[i].addr);
			printf("\n\t\t手机号码： %s",per[i].celephone);
			printf("\n\t\t家庭电话号码：%s",per[i].homephone); 
			printf("\n\t\t公司名称：%s",per[i].company);
			printf("\n\t\t电子邮件：%s",per[i].email);
			printf("\n\t\tQQ号码：%ld",per[i].QQ);
			printf("\n\t\t________________________________");
			printf("\n\t\t是否修改?（1代表修改；2代表不修改）"); 
			printf("          请输入您的数字选择:    ");
			scanf("%d",&j);
		    if (j==1) 
			 {
				xiugaixiangmu(i);
				printf("\n\t\t修改成功"); 
				printf("\n\t\t是否继续修改?（1代表继续；2代表不继续）"); 
				printf("          请输入您的数字选择:    ");
				scanf("%d",&j);
		        printf("          请输入您的数字选择:    ");
				if (j==1)  
				  xiugaixiangmu(i); 
				break; 
			 } 
		}  
	} 
	if (findmark==0) 
	{ 
		printf("\n\t\t对不起!没有该联系人的纪录!"); 
		printf("\n\t\t是否继续修改?（1代表继续；2代表不继续）"); 
		printf("          请输入您的数字选择:    ");
		scanf("%d",&j);
		if (j==1)  
		   xiugaibycelephone(); 
		return; 
	} 
}



void xiugaixiangmu(int a)//*修改项目*//
{
	int i;
	system("cls"); 
	system("color c0");
	printf("\n\t\t             请输入您要修改的项目               ");
	printf("\n\t\t\n");
	printf("\n\t\t1-手机号码\n");
	printf("\n\t\t2-姓名\n");
	printf("\n\t\t3-家庭电话号码\n"); 
	printf("\n\t\t4-QQ号码\n");
	printf("\n\t\t5-地址\n");
	printf("\n\t\t6-邮编\n");
	printf("\n\t\t7-电子邮件\n");
	printf("\n\t\t8-回主菜单\n"); 
	printf("\n\t\t\n"); 
	printf("          请输入您的数字选择:    ");
	scanf("%d",&i);
loop9:	switch (i) 
	{

		case 1:printf("请输入手机号码：");
			scanf("%s",&per[a].celephone);break;
		case 2:printf("请输入姓名：");
			scanf("%s",&per[a].name);break;
		case 3:printf("请输入家庭电话号码：");
			scanf("%s",&per[a].homephone);break;
		case 4:printf("请输入QQ号码：");
			scanf("%s",&per[a].QQ);break;
		case 5:printf("请输入地址：");
			scanf("%s",&per[a].addr);break;
		case 6:printf("请输入邮编：");
			scanf("%s",&per[a].youbian);break;
		case 7:printf("请输入email：");
			scanf("%s",&per[a].email);break;
		case 8:mainmenu();break;
		default: printf("对不起！您的输入有误！请重新输入:   ");goto loop9;
	}
}


void listmenu()//*排序菜单*//
{ 
    int i,j;
    system("cls");
	system("color b0");
	if(num==0) 
	{ 
		printf("\n\t\t对不起，文件中无任何纪录"); 
		printf("\n\t\t请按任意数字键返回主菜单"); 
		scanf("%d",&j); 
		return;  
	} 
	else
	{
	   system("cls");
	   system("color 12");
	   printf("\n\t\t              排   序   菜   单                 "); 
	   printf("\n\t\t                 1-按姓名排序                   ");
	   printf("\n\t\t                 2-按手机号码排序                   "); 
	   printf("\n\t\t                 3-返回主菜单                   "); 
       printf("                 请输入您的数字选择:    ");
loop10:		scanf("%d",&i); 
	   switch(i) 
	   { 
		 case 1:listbyname();break; 
		 case 2:listbycelephone();break; 
		 case 3:mainmenu();break; 
		 default:printf("对不起！您的输入有误！请重新输入:   ");goto loop10; 
	   } 
	}
}


void listbyname()//*按姓名排序*// 
{ 
	int i,j,k; 
	struct person tmp; 
	for (i=1;i<num;i++) 
	{ 
		if(strcmp(per[i].name,per[i-1].name)<0) 
		{ 
			tmp=per[i]; 
			j=i-1; 
			do 
			{ 
				per[j+1]=per[j]; 
				j--; 
			}
			while ((strcmp(tmp.name,per[j].name)<0&&j>=0)); 
			per[j+1]=tmp; 
		} 
	} 
	    printf("\n\t\t排序成功,是否显示?（1代表继续；2代表不继续）"); 
		printf("          请输入您的数字选择:    ");
		scanf("%d",&k);
		if (k==1)   
		   showall(); 
	    return; 
} 


void listbycelephone()//*按手机号码排序*// 
{ 
	int i,j,k; 
	struct person tmp; 
	for (i=1;i<num;i++) 
	{ 
		if(strcmp(per[i].celephone,per[i-1].celephone)<0) 
		{ 
			tmp=per[i]; 
			j=i-1; 
			do 
			{ 
				per[j+1]=per[j]; 
				j--; 
			}while ((strcmp(tmp.celephone,per[j].celephone)<0)&&j>=0); 
			per[j+1]=tmp; 
		} 
	} 
	printf("\n\t\t排序成功,是否显示?（1代表继续；2代表不继续）"); 
	printf("          请输入您的数字选择:    ");
	scanf("%d",&k);
	if (k==1) 
	   showall(); 
	return; 
}








void showall()//*输 出 全 部 信 息*// 
{ 
	int i,j; 
	system("cls");
	system("color 3b"); 
	if(num!=0) 
	{ 
		printf("\n\t\t*************** 以下为通讯录所有信息************"); 
		for (i=0;i<num;i++) 
		{ 
			printf("\n\t\t________________________________"); 
			printf("\n\t\t名字： %s",per[i].name); 
			printf("\n\t\t性别： %s",per[i].sex); 
			printf("\n\t\t年龄： %d",per[i].nianling); 
			printf("\n\t\t邮编 ： %ld",per[i].youbian);
			printf("\n\t\t地址： %s",per[i].addr);
			printf("\n\t\t手机号码： %s",per[i].celephone);
			printf("\n\t\t家庭电话号码：%s",per[i].homephone); 
			printf("\n\t\t公司名称：%s",per[i].company);
			printf("\n\t\t电子邮件：%s",per[i].email);
			printf("\n\t\tQQ号码：%ld",per[i].QQ);
			printf("\n\t\t________________________________");
			printf("\t\t"); 
			if (i+1<num) 
			{ 
				printf("\n\t\t__________________________"); 
				system("pause"); 
			} 
		}	 
		printf("\n\t\t************************************************"); 
	} 
	else 
	   printf("\n\t\t对不起!通讯录中无任何纪录!"); 
	printf("\n\t\t请按任意数字键返回主菜单"); 
	scanf("%d",&j); 
	return;  
} 




void writetofile()//*写入文件*// 
{ 
	int i,k;
	system("cls"); 
	system("color 84");
	if ((fp=fopen("per.bin","wb"))==NULL) 
	{ 
		printf("\n\t\t文件打开失败"); 
	} 
	for (i=0;i<num;i++) 
	{ 
		if (fwrite(&per[i],sizeof(struct person),1,fp)!=1) 
		{ 
			printf("\n\t\t写入文件错误!\n"); 
		} 
	} 
	fclose(fp); 
	printf("\n\t\t通讯录文件已保存"); 
	printf("\n\t\t请按任意数字键返回主菜单"); 
	scanf("%d",&k); 
	return; 
} 

 





void readfromfile()//*读取文件*// 
{ 
    int i,j,k;
    system("cls"); 
	system("color 2b");
	if((fp=fopen("per.bin","rb"))==NULL) 
	{ 
		printf("\n\t\t****************************");
		printf("\n\t\t*                          *");
		printf("\n\t\t*                          *");
		printf("\n\t\t*    通讯录文件不存在!     *"); 
		if ((fp=fopen("per.bin","wb"))==NULL) 
		{ 
			printf("\n*        建立失败!         *");
			printf("\n*                          *");
			printf("\n*                          *");
			printf("\n****************************");
			exit(0); 
		} 
		else 
		{
			printf("\n\t\t*    通讯录文件已建立!     *"); 
			printf("\n\t\t*                          *");
			printf("\n\t\t*                          *");
			printf("\n\t\t****************************");
			printf("\n\t\t      按任意键进入主菜单    "); 
			printf("\n\t\t          请输入您的数字选择:    ");
		    scanf("%d",&k);
			return;		
		} 
		exit(0); 
	} 
	fseek(fp,0,2); //*文件位置指针移动到文件末尾*// 
	if (ftell(fp)>0) //*文件不为空*// 
	{ 
		rewind(fp); //*文件位置指针移动到文件开始位置*// 
		for (num=0;!feof(fp) && fread(&per[num],sizeof(struct person),1,fp);num++); 
		printf("\n\t\t****************************");
		printf("\n\t\t*                          *");
		printf("\n\t\t*                          *");
		printf("\n\t\t*     文件导入成功!        *");  
		printf("\n\t\t*                          *");
		printf("\n\t\t*                          *");
		printf("\n\t\t****************************");
		printf("\n\t\t     按1显示所有信息，按2回主菜单！     "); 
		printf("\t\t          请输入您的数字选择:    ");
		scanf("%d",&j); 
		if(j==1)
		  showall(); 
	}
else
 {
	printf("\n\t\t****************************");
	printf("\n\t\t*                          *");
	printf("\n\t\t*                          *");
	printf("\n\t\t*     文件导入成功!        *"); 
	printf("\n\t\t*  通讯录文件中无任何纪录! *"); 
	printf("\n\t\t*                          *");
	printf("\n\t\t*                          *");
	printf("\n\t\t****************************");
	printf("\n\t\t请按任意数字键返回主菜单"); 
	scanf("%d",&i); 
	return; 
}
} 



void deleteall()//*删除所有信息*//
{ 
    int i,j;
	system("cls"); 
	system("color 50");
	printf("\n\t\t确认删除?\n");
	printf("请按1和2（1代表确认；2代表不删除）\n ");
	scanf("%d",&i);
	if (i==1) 
	{ 
		fclose(fp); 
		if ((fp=fopen("per.bin","wb"))==NULL) 
	     { 
		    printf("\n\t\t不能打开文件，删除失败"); 
		    readfromfile(); 
	     } 
	    num=0; 
	    printf("\n\t\t纪录已删除!"); 
	    printf("\n\t\t请按任意数字键返回主菜单"); 
	    scanf("%d",&j); 
	    return; 
	} 

} 
