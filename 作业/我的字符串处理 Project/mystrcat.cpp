void mystrcat(char str1[],char str2[])
{
	char str3[100];
	int i,j;
	for(i=0;str1[i]!='\0';i++)
	{
		str3[i]=str1[i];
	}
	for(j=0,i=i;str2[j]!='\0';j++,i++)
	{
		str3[i]=str2[j];
	}
	str3[i]='\0';
	printf("连接后的字符串为:%s\n",str3);
}
