void liststu()
{
	STU *stu1;
	
	printf("\n同学列表:\n");
	bound('_',25);
	stu1=stu_first;
	
	while(stu)
	{
		printf("学号：d%\n",stu->no);
		printf("姓名：s%\n",stu->name);
		printf("性别：s%\n",stu->sex);
		printf("年龄：d%\n",stu->age);
		printf("电话：s%\n",stu->mobile);
		printf("  QQ：s%\n",stu->QQ);
		printf("地址：s%\n",stu->address);
		bound('_',25);
		stu1=stu1->next;
	} 
	printf("\n按任意键返回！\n");
	return 0;
}
