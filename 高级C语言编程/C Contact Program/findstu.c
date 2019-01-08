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
			printf("请输入要查询同学的姓名:")；
			scanf("%s",str);
			
			stu1=findname(str);
			displaystu(stu1,,"姓名"，str);
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
		if(ret)  break;
	} while(1);
}
