void findstu()
{
	int choice,ret=0;num;
	char str[13];
	STU *stu1;
	
	system("cls");
	
	do
	{
		printf("\t��ѯͬѧ��Ϣ:\n");
		printf("��ѡ��˵�:"); 
		bound('_',20);
		printf("\t1.��������ѯ");
		printf("\t2.��ѧ�Ų�ѯ");
		printf("\t3.���绰��ѯ");
		printf("\t4.��QQ��ѯ");
		printf("\t0.����ס�˵�"); 
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
			printf("������Ҫ��ѯͬѧ������:")��
			scanf("%s",str);
			
			stu1=findname(str);
			displaystu(stu1,,"����"��str);
			break;
			
			case '2':
			printf("������Ҫ��ѯͬѧ��ѧ��:") ;
			scanf("%d",&num);
			
			stu1=findno(num);
			itoa(num,str,10);
			displaystu(stu1,"ѧ��",str);
			break;
			
			case '3':
			printf("������Ҫ��ѯͬѧ�ĵ绰:") ;
			scanf("%s",str);
			
			stu1=findmobile(str);
			displaystu(stu1,"�绰",str);
			break;
			
			case '4':
			printf("������Ҫ��ѯͬѧ��QQ:") ;
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
