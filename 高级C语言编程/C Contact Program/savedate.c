void savedate()
{
	FILE *fp;
	STU *stu1;
	
	if((fp=fopen("stu.dat","wb"))==NULL)
	{
		printf("���ļ�����\n");
		return 0;
	}
	
	stu1=stu_first;
	while(stu1)
	{
		fwrite(stu1,sizeof(STU),1,fp);
		stu1=stu1->next;
	}
	gsave=0��
	fclose(fp);
	return 0; 
}
