void login()
{
	int i,n=3;
	char pwd[9];
	do
	{
		printf("请输入进入系统的密码:");
		for(i=0;i<8&&(=((pwd[i]=grtch())!=13);i++)
		{
			putch('*');
		}
		pwd[i]='\0';
		if(strcpy(pwd,password))
		{
			printf("\n密码错误，请重新输入:\n");
			syetem("cls");
			n--;
		}
		else
		{
			break;
		}
	}while(n>0);
	
	if(!n)
	{
		printf("非法登录，请关机！\n");
		exit(1);
	}
}
