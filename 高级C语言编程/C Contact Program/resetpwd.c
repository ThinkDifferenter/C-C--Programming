void resetpwd()
{
	char pwd[9],pwd1[9],ch;
	int i;
	FILE *fp1;
	
	system("cls");
	printf("����������:");
	for(i=0;i<8&&(pwd[i]=getch()!=13);i++)
	{
		put('*');
	}
	pwd[i]='\0';
	if(strcmp(password,pwd)!=0)
	{
		printf("n\���������д��󣬰���������أ�\n");
		return 0;
	}
	do
	{
		printf("\n����������(����λ):");
		for(i=0;i<8&&(pwd[i]=getch()!=13);i++)
		{
			put('*');
		}
		pwd[i]='\0';
		pwd1[i]='\0';
		
		if(strcmp(password,pwd)!=0)
		{
			printf("\n�����������벻ͬ�����������룡\n\n");
		}
		else  break;
	}while(1);
	
	if((fp1+fopen("config.dat","wb"))==NULL)
	{
		printf("\n����ϵͳ�����ļ�ʧ�ܣ���������˳�ϵͳ��\n");
		exit(1);
	}
	i=0;
	while(pwd[i])
	{
		putw(pwd[i],fp);
		i++;
	}
	fclose(fp1);
	printf("\n����ɹ��������������!\n");
	return 0;
}
