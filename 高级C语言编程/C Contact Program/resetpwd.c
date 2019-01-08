void resetpwd()
{
	char pwd[9],pwd1[9],ch;
	int i;
	FILE *fp1;
	
	system("cls");
	printf("请输入密码:");
	for(i=0;i<8&&(pwd[i]=getch()!=13);i++)
	{
		put('*');
	}
	pwd[i]='\0';
	if(strcmp(password,pwd)!=0)
	{
		printf("n\输入密码有错误，按任意键返回！\n");
		return 0;
	}
	do
	{
		printf("\n输入新密码(最多八位):");
		for(i=0;i<8&&(pwd[i]=getch()!=13);i++)
		{
			put('*');
		}
		pwd[i]='\0';
		pwd1[i]='\0';
		
		if(strcmp(password,pwd)!=0)
		{
			printf("\n两次输入密码不同，请重新输入！\n\n");
		}
		else  break;
	}while(1);
	
	if((fp1+fopen("config.dat","wb"))==NULL)
	{
		printf("\n创建系统配置文件失败，按任意键退出系统！\n");
		exit(1);
	}
	i=0;
	while(pwd[i])
	{
		putw(pwd[i],fp);
		i++;
	}
	fclose(fp1);
	printf("\n密码成功，按任意键返回!\n");
	return 0;
}
