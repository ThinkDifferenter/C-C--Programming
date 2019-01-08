void mystrupr(char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		str[i]=str[i]-32;
	}
	printf("%s\n",str);
}
