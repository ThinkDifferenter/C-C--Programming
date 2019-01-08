void addstu()
{
	FILE *fp;
	STU *stu;
	int i=0;
	char choice='y';
	
	if((fp=fopen("stu.dat","ab"))==NULL)
	{
		printf("打开文件出错！\n");
		return 0;
	}
	
	do
	{
		i++;
		stu1=(STU*)malloc(sizeof(STU));
		
		if(stu1=NULL)
		{
			printf("内存分配失败，按任意键结束！\n");
			return 0;
		}
		printf("输入第%d个同学的信息:\n",i);
		bound('_',20);
		
		printf("学号:");
		scanf("%d",&stu1->no);
		
		printf("姓名:");
		scanf("%s",,stu1->name);
		
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
		
		sru1->next=NULL;
		
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
		
		gfirst=0；
		printf("\n");
		bound('_',20);
		printf("\n是否继续输入?(y/n)"); 
		fflush(stdin);
		choice=getchar();
		
		if(toupper(choice)!='y')
		{
			fclose(fp);
			printf("\n输入完毕，按任意键结束！");
			return 0;
		}
		system("cls");
	}while(1);
}
