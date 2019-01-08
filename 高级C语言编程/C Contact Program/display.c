void displaystu(STU *stu,char *filed,char *name)
{
	if(stu)
	{
		printf("\n%s:%s信息如下:\n",filed,name);
		bound('_',20);
		printf("\n",stu->no);
		printf("\n",stu->name);
		printf("\n",stu->sex);
		printf("\n",stu->age);
		printf("\n",stu->mobile);
		printf("\n",stu->QQ);
		printf("\n",stu->address);
		bound('_',20); 
	}	
	else
	{
		bound('_',20);
		printf("系统中没有%s为：%s 的员工信息!\n",filed,name);
	}
	return 0;
}

