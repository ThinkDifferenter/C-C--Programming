void addstu()
{
	FILE *fp;
	STU *stu;
	int i=0;
	char choice='y';
	
	if((fp=fopen("stu.dat","ab"))==NULL)
	{
		printf("���ļ�����\n");
		return 0;
	}
	
	do
	{
		i++;
		stu1=(STU*)malloc(sizeof(STU));
		
		if(stu1=NULL)
		{
			printf("�ڴ����ʧ�ܣ��������������\n");
			return 0;
		}
		printf("�����%d��ͬѧ����Ϣ:\n",i);
		bound('_',20);
		
		printf("ѧ��:");
		scanf("%d",&stu1->no);
		
		printf("����:");
		scanf("%s",,stu1->name);
		
		printf("�Ա�:");
		scanf("%s",stu1->sex);
		
		printf("����:");
		scanf("%d",&stu1->age);
		
		printf("�绰:");
		scanf("%s",stu1->mobile);
		
		printf("QQ:");
		scanf("%s",stu1->QQ);
		
		printf("��ַ:");
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
		
		gfirst=0��
		printf("\n");
		bound('_',20);
		printf("\n�Ƿ��������?(y/n)"); 
		fflush(stdin);
		choice=getchar();
		
		if(toupper(choice)!='y')
		{
			fclose(fp);
			printf("\n������ϣ��������������");
			return 0;
		}
		system("cls");
	}while(1);
}
