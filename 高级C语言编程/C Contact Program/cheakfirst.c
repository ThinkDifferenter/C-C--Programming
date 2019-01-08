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
			printf("\n设置登录的系统的密码(八位):")；
			for(i=0;i<8&&(pwd[i]=getch())!=13;i++)
			{
				putch("*");
			} 
			printf("\n再次输入登录密码:");
			for(i=0;i<8(&&pwd[i]=getch())!=13;i++)
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
		if((fp1=fopen("config.dat"."wb"))==NULL)
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
		strcpy(password,pwd);
	}
}
