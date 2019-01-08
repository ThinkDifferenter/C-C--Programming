char *modi_filed(char *filed,char *s,int n)
{
	char *str;
	str=malloc(sizeof(char)*n);
	if(str==NULL)
	{
		printf("内存分配失败，按任意键返回！\n");
		return NULL;
	}
	printf("原%s:%s\n",filed,s);
	printf("修改为(不超过%d个字符):",n);
	scanf("%s",str);
	
	return str;
}
