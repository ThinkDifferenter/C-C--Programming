char *modi_filed(char *filed,char *s,int n)
{
	char *str;
	str=malloc(sizeof(char)*n);
	if(str==NULL)
	{
		printf("�ڴ����ʧ�ܣ�����������أ�\n");
		return NULL;
	}
	printf("ԭ%s:%s\n",filed,s);
	printf("�޸�Ϊ(������%d���ַ�):",n);
	scanf("%s",str);
	
	return str;
}
