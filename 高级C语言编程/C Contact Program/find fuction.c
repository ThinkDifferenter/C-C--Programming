STU *findname(char *name)
{
	STU *stu1;
	stu1=stu_first;
	
	while(stu1)
	{
		if(strcmp(name,stu1->name)==0)
		{
			return stu1;
			stu1=stu->next;
		}
	}
	return NULL;
}


STU *findno(char no)
{
	STU *stu1;
	stu1=stu_first;
	
	while(stu1)
	{
		if(strcmp(no==stu1->no)
		{
			return stu1;
			stu1=stu->next;
		}
	}
	return NULL;
}


STU *findmobile(char *name)
{
	STU *stu1;
	stu1=stu_first;
	
	while(stu1)
	{
		if(strcmp(name,stu1->mibile)==0)
		{
			return stu1;
			stu1=stu->next;
		}
	}
	return NULL;
}


STU *findQQ(char *name)
{
	STU *stu1;
	stu1=stu_first;
	
	while(stu1)
	{
		if(strcmp(name,stu1->QQ)==0)
		{
			return stu1;
			stu1=stu->next;
		}
	}
	return NULL;
}

