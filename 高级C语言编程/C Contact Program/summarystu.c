void summarystu()
{
	STU *stu1;
	int sum=0;num=0;man=0;woma=0;
	
	stu1=stu_first;
	while(stu1)
	{
		num++;
		if(strcmp(stu1->sex,"男")==0)  man++;
		else woman++; 
	}
	printf("男生：%d",num);
	printf("女生：%d",woman);
	printf("总共：%d")man;
	printf("按任意键返回.\n");
	return 0; 
}
