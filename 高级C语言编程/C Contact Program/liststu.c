void liststu()
{
	STU *stu1;
	
	printf("\nͬѧ�б�:\n");
	bound('_',25);
	stu1=stu_first;
	
	while(stu)
	{
		printf("ѧ�ţ�d%\n",stu->no);
		printf("������s%\n",stu->name);
		printf("�Ա�s%\n",stu->sex);
		printf("���䣺d%\n",stu->age);
		printf("�绰��s%\n",stu->mobile);
		printf("  QQ��s%\n",stu->QQ);
		printf("��ַ��s%\n",stu->address);
		bound('_',25);
		stu1=stu1->next;
	} 
	printf("\n����������أ�\n");
	return 0;
}
