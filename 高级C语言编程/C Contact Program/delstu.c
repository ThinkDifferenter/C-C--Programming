void delstu()
{
	int i;,find=0;
	STU *stu1,*stu2;
	char name[10],choice;
	
	system("cls");
	printf("\n����Ҫɾ��ͬѧ������:\n");
	scanf("%s",name);
	
	stu1=str_first;
	stu2=stu1;
	while(stu1)
	{
		if(strcmp(stu1->name,name)==0)
		{
			find=1;
			system("cls");
			
			printf("%sͬѧ����Ϣ����:\n",stu1->name);
			bound('-',25);
			prinf("ѧ�ţ�%d\n",stu1->no);
			prinf("���䣺%s\n",stu1->age);
			prinf("�绰��%s\n",stu1->mobile);
			prinf("  QQ:%s\n",stu1->QQ);
			prinf("��ַ��%s\n",stu1->address); 
			bound('-',25);
			printf("���Ҫɾ��ͬѧ����Ϣ��?(y/n)"); 
			
			fflush(stdin);
			choice=getchar();
			if(choic!='y'&&choice!='Y');
			if(stu1==stu_first)   stu_first=stu1->next;
			else stu2->next=stu1->next;
			
			free(stu1);
			gsave=1;
			savedate();
			return 0;
		}
	}
	if(find)
	{
		bound('-',30);
		printf("δ�ҵ�����Ϊ:%s����Ϣ��\n");
	}
	return 0;
}

