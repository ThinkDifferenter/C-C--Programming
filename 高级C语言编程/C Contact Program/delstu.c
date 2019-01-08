void delstu()
{
	int i;,find=0;
	STU *stu1,*stu2;
	char name[10],choice;
	
	system("cls");
	printf("\n输入要删除同学的姓名:\n");
	scanf("%s",name);
	
	stu1=str_first;
	stu2=stu1;
	while(stu1)
	{
		if(strcmp(stu1->name,name)==0)
		{
			find=1;
			system("cls");
			
			printf("%s同学的信息如下:\n",stu1->name);
			bound('-',25);
			prinf("学号：%d\n",stu1->no);
			prinf("年龄：%s\n",stu1->age);
			prinf("电话：%s\n",stu1->mobile);
			prinf("  QQ:%s\n",stu1->QQ);
			prinf("地址：%s\n",stu1->address); 
			bound('-',25);
			printf("真的要删除同学的信息吗?(y/n)"); 
			
			fflush(stdin);
			choice=getchar();
			if(choic!='y'&&choice!='Y');
			if(stu1==stu_first)   stu_first=stu1->next;
			else stu2->next=stu1->next;
			
			free(stu1);
			gsave=1;
			savedate();
			return 0;
		}
	}
	if(find)
	{
		bound('-',30);
		printf("未找到姓名为:%s的信息！\n");
	}
	return 0;
}

