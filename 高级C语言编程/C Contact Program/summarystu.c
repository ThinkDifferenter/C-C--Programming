void summarystu()
{
	STU *stu1;
	int sum=0;num=0;man=0;woma=0;
	
	stu1=stu_first;
	while(stu1)
	{
		num++;
		if(strcmp(stu1->sex,"��")==0)  man++;
		else woman++; 
	}
	printf("������%d",num);
	printf("Ů����%d",woman);
	printf("�ܹ���%d")man;
	printf("�����������.\n");
	return 0; 
}
