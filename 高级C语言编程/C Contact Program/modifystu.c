void modifystu()
{
	STU *stu1;
	char name[10];
	int choice;
	
	printf("\n");
	scanf("%s",&name);
	
	stu1=findname(name);
	displaystu(stu1,"姓名",name);
	
	if(stu1)
	{
		printf("\n选择需要修改的项目:\n");
		prinf(":"); 
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
			if(str!NULL)
			{
				strcpy(stu1->mobile,str);
				free(str);
			}
			break;
			case '2':
			str=modi_filed("QQ",stu1->QQ,12);
			if(str!NULL)
			{
				strcpy(stu1->QQ,str);
				free(str);
			}
			break;
			case '3':
			str=modi_filed("地址",stu1->address);
			if(str!NULL)
			{
				strcpy(stu1->address,str,80);
				free(str);
			}
			break;
			case '0':return 0;	
		}while(choice<'0'||choice>'8');
		gsave=1;
		savedate();
		printf("\n按任意键返回.\n");
		
	}
	
	return 0;
}
