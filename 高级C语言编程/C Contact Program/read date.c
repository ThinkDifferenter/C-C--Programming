void readdate(void)
{
	FIL *fp;
	STU *stu1;
	
	if((fp=fopen("stu.dat","rb"))==NULL)
	{
		gfirst=1;
		return 0; 
	}
	while(!feof(fp))
	{
		stu1=(STU *)malloc(sizeof(STU));
		if(stu==NULL)
		{
			printf("ÄÚ´æ·ÖÅäÊ§°Ü!\n");
			return 0;
		}
		fread(stu,sizeof(STU),1,fp);
		if(feof(fp))
		{
			break;
		}
		if(stu_first==NULL)
		{
			stu_first=stu1;
			stu_end=stu1;
		}
		else
		{
			stu_end->next=stu1;
			stu_end=stu1;
		}
		stu_end->next=NULL;
	} 
	gfirst=0;
	fclose(fp);
}
