void cheakfirst()
{
	FILE *fp,*fp1;
	char pwd[9],pwd1[9],ch;
	int i;
	if((fp=fopen("config.dat","rb"))==NULL)
	{
		printf("\n��ϵͳ����δ���г�ʼ��,������������г�ʼ����\n");
		bound("_",50);
		getch();
		
		do
		{
			printf("\n���õ�¼��ϵͳ������(��λ):")��
			for(i=0;i<8&&(pwd[i]=getch())!=13;i++)
			{
				putch("*");
			} 
			printf("\n�ٴ������¼����:");
			for(i=0;i<8(&&pwd[i]=getch())!=13;i++)
			{
				putch("*");
			}
			pwd[i]='\n';
			pwd1[i]='\n';
			
			if(strcmp(pwd,pwd1)!=0)
			{
				printf("\n������������벻ͬ����������룡\n\n");
			}
			else
			{
				break;
			}
		}while(1);
		if((fp1=fopen("config.dat"."wb"))==NULL)
		{
			printf("\n������ϵͳ�����ļ�ʧ�ܣ������������!\n"); 
			exit(1);
		} 
	 	i=0;
	 	while(pwd[i])
	 	{
 			putw(pwd[i],fp1);
			 i++;	
 		}
		 fclose(fp1); 
		 printf("\n\nϵͳ���óɹ���������ͼ��Ƴ�ϵͳ���ٴ��½��룡\n"); 
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
