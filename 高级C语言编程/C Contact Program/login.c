void login()
{
	int i,n=3;
	char pwd[9];
	do
	{
		printf("���������ϵͳ������:");
		for(i=0;i<8&&(=((pwd[i]=grtch())!=13);i++)
		{
			putch('*');
		}
		pwd[i]='\0';
		if(strcpy(pwd,password))
		{
			printf("\n�����������������:\n");
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
		printf("�Ƿ���¼����ػ���\n");
		exit(1);
	}
}
